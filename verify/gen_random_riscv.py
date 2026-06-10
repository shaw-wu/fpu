#!/usr/bin/env python3
"""Build mixed RISC-V regression suites for all supported FP64 ops."""

from __future__ import annotations

import argparse
import random
import subprocess
from pathlib import Path
from typing import Dict, Iterable, List, Sequence, Tuple

from gen_directed_riscv import build_cases as build_directed_cases
from gen_directed_riscv import generate_vectors as generate_directed_vectors
from gen_directed_riscv import parse_ops
from riscv_adapter import (
    ALL_RM,
    OP_SPECS,
    RM_NAMES,
    RM_RNE,
    SPECIAL_FP64_VALUES,
    SPECIAL_INT32_VALUES,
    TF_RM_FLAGS,
    adapt_testfloat_case,
    format_vector,
    oracle_case,
)


TESTFLOAT_SOURCE_OPS = {"fadd.d", "fsub.d", "fmul.d", "fdiv.d"}


def fetch_testfloat_cases(op_name: str, rm: int, seed: int) -> List[Tuple[int, int, int, int]]:
    spec = OP_SPECS[op_name]
    if spec.testfloat_func is None:
        raise ValueError(f"{op_name} does not have a testfloat source")

    cmd = ["./testfloat_gen", spec.testfloat_func]
    if spec.rm_sensitive:
        cmd.append(TF_RM_FLAGS[rm])
    if spec.testfloat_exact:
        cmd.append("-exact")
    cmd.extend(["-seed", str(seed)])

    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    cases: List[Tuple[int, int, int, int]] = []
    for raw_line in result.stdout.splitlines():
        line = raw_line.strip()
        if not line:
            continue
        parts = line.split()
        if spec.arity == "binary_fp":
            if len(parts) != 4:
                raise ValueError(f"unexpected testfloat output for {op_name}: {raw_line}")
            a_bits = int(parts[0], 16)
            b_bits = int(parts[1], 16)
            raw_res = int(parts[2], 16)
            raw_flags = int(parts[3], 16)
        elif spec.arity == "unary_fp":
            if len(parts) != 3:
                raise ValueError(f"unexpected testfloat output for {op_name}: {raw_line}")
            a_bits = int(parts[0], 16)
            b_bits = 0
            raw_res = int(parts[1], 16)
            raw_flags = int(parts[2], 16)
        elif spec.arity == "unary_int":
            if len(parts) != 3:
                raise ValueError(f"unexpected testfloat output for {op_name}: {raw_line}")
            a_bits = int(parts[0], 16)
            b_bits = 0
            raw_res = int(parts[1], 16)
            raw_flags = int(parts[2], 16)
        else:
            raise ValueError(f"unsupported arity {spec.arity}")
        cases.append((a_bits, b_bits, raw_res, raw_flags))
    return cases


def sample_cases(cases: Sequence[Tuple[int, int, int, int]], count: int, seed: int) -> List[Tuple[int, int, int, int]]:
    if count > len(cases):
        raise ValueError(f"requested {count} cases but source only emitted {len(cases)}")
    rng = random.Random(seed)
    selected = list(cases)
    rng.shuffle(selected)
    return selected[:count]


def random_fp64_bits(rng: random.Random) -> int:
    roll = rng.randrange(100)
    if roll < 30:
        return rng.choice(SPECIAL_FP64_VALUES)
    if roll < 45:
        sign = rng.getrandbits(1)
        quiet = rng.getrandbits(1)
        payload = rng.getrandbits(51) | 1
        frac = (quiet << 51) | payload
        return (sign << 63) | (0x7FF << 52) | frac
    if roll < 60:
        sign = rng.getrandbits(1)
        frac = rng.randrange(1, 1 << 52)
        return (sign << 63) | frac
    if roll < 75:
        sign = rng.getrandbits(1)
        exp = rng.choice([1, 2, 1022, 1023, 1024, 2045, 2046])
        frac = rng.getrandbits(52)
        return (sign << 63) | (exp << 52) | frac
    return rng.getrandbits(64)


def random_int32_bits(rng: random.Random) -> int:
    if rng.randrange(100) < 40:
        return rng.choice(SPECIAL_INT32_VALUES)
    return rng.getrandbits(32)


def local_random_operands(op_name: str, rng: random.Random) -> Tuple[int, int]:
    spec = OP_SPECS[op_name]
    if spec.arity == "binary_fp":
        return random_fp64_bits(rng), random_fp64_bits(rng)
    if spec.arity == "unary_fp":
        return random_fp64_bits(rng), 0
    if spec.arity == "unary_int":
        return random_int32_bits(rng), 0
    raise ValueError(f"unsupported arity {spec.arity}")


def build_vectors_for_op(
    op_name: str,
    count_per_rm: int,
    seed: int,
    *,
    cross_check_testfloat: bool,
) -> List[str]:
    spec = OP_SPECS[op_name]
    rms = ALL_RM if spec.rm_sensitive else (RM_RNE,)
    lines: List[str] = []

    if op_name in TESTFLOAT_SOURCE_OPS:
        for rm in rms:
            rm_seed = seed + spec.sel * 1009 + rm * 131
            raw_cases = fetch_testfloat_cases(op_name, rm, rm_seed)
            sampled = sample_cases(raw_cases, count_per_rm, rm_seed ^ 0x5A5A_1234)
            for a_bits, b_bits, raw_res, raw_flags in sampled:
                exp_res, exp_flags = oracle_case(op_name, a_bits, b_bits, rm)
                if cross_check_testfloat:
                    ref_res, ref_flags = adapt_testfloat_case(op_name, raw_res, raw_flags)
                    if (exp_res, exp_flags) != (ref_res, ref_flags):
                        raise AssertionError(
                            f"testfloat mismatch op={op_name} rm={RM_NAMES[rm]} "
                            f"a={a_bits:016x} b={b_bits:016x} "
                            f"oracle=({exp_res:016x},{exp_flags:02x}) "
                            f"testfloat=({ref_res:016x},{ref_flags:02x})"
                        )
                lines.append(format_vector(a_bits, b_bits, exp_res, exp_flags, rm, spec.sel))
        return lines

    rng = random.Random(seed + spec.sel * 4099)
    for rm in rms:
        for _ in range(count_per_rm):
            a_bits, b_bits = local_random_operands(op_name, rng)
            exp_res, exp_flags = oracle_case(op_name, a_bits, b_bits, rm)
            lines.append(format_vector(a_bits, b_bits, exp_res, exp_flags, rm, spec.sel))
    return lines


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate mixed RISC-V regression vectors for all supported ops")
    parser.add_argument("--ops", default="all", help="comma-separated op list or 'all'")
    parser.add_argument("--output", default="fpu_test_suite.tmp", help="vector output path")
    parser.add_argument(
        "--count-per-rm",
        type=int,
        default=16,
        help="random vectors per rm for rm-sensitive ops, or total vectors for rm-insensitive ops",
    )
    parser.add_argument("--seed", type=int, default=1, help="base random seed")
    parser.add_argument("--include-directed", action="store_true", help="prepend the directed suite before shuffling")
    parser.add_argument(
        "--cross-check-testfloat",
        action="store_true",
        help="compare long arithmetic oracle results against canonicalized testfloat outputs",
    )
    parser.add_argument("--no-shuffle", action="store_true", help="keep vectors grouped instead of shuffling")
    args = parser.parse_args()

    selected_ops = parse_ops(args.ops)
    output_lines: List[str] = []
    per_op_counts: Dict[str, int] = {}

    if args.include_directed:
        directed_lines = generate_directed_vectors(build_directed_cases(), selected_ops)
        output_lines.extend(directed_lines)

    for op_name in selected_ops:
        lines = build_vectors_for_op(
            op_name,
            args.count_per_rm,
            args.seed,
            cross_check_testfloat=args.cross_check_testfloat,
        )
        output_lines.extend(lines)
        per_op_counts[op_name] = len(lines)

    if not args.no_shuffle:
        rng = random.Random(args.seed ^ 0x1357_2468)
        rng.shuffle(output_lines)

    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(output_lines) + "\n", encoding="ascii")

    print(f"wrote {len(output_lines)} vectors to {output_path}")
    if args.include_directed:
        directed_count = len(generate_directed_vectors(build_directed_cases(), selected_ops))
        print(f"included {directed_count} directed vectors")
    for op_name in selected_ops:
        print(f"{op_name}: {per_op_counts[op_name]} random vectors")


if __name__ == "__main__":
    main()
