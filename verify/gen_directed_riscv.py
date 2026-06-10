#!/usr/bin/env python3
"""Generate directed RISC-V semantic vectors for all supported FP64 ops."""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List, Sequence

from riscv_adapter import (
    ALL_RM,
    CANONICAL_NAN_D,
    INT32_MAX,
    OP_SPECS,
    POS_INF,
    POS_ZERO,
    RM_NAMES,
    RM_RNE,
    RM_RTZ,
    UINT32_MAX,
    decode_fp64,
    format_vector,
    int_to_fp64_bits,
    oracle_case,
)


NEG_ZERO = 0x8000_0000_0000_0000
NEG_INF = 0xFFF0_0000_0000_0000
MAX_FINITE = 0x7FEF_FFFF_FFFF_FFFF
MIN_SUB = 0x0000_0000_0000_0001
MAX_SUB = 0x000F_FFFF_FFFF_FFFF
MIN_NORMAL = 0x0010_0000_0000_0000
ONE = 0x3FF0_0000_0000_0000
TWO = 0x4000_0000_0000_0000
THREE = 0x4008_0000_0000_0000
HALF = 0x3FE0_0000_0000_0000
NEG_ONE = 0xBFF0_0000_0000_0000
NEG_HALF = 0xBFE0_0000_0000_0000
QNAN = CANONICAL_NAN_D
SNAN = 0x7FF0_0000_0000_0001
HALF_ULP_AT_ONE = 0x3CA0_0000_0000_0000
NEXT_HALF_ULP_AT_ONE = HALF_ULP_AT_ONE + 1


@dataclass(frozen=True)
class DirectedCase:
    op_name: str
    a_bits: int
    b_bits: int
    rms: Sequence[int]
    note: str


def case(op_name: str, a_bits: int, b_bits: int, rms: Sequence[int], note: str) -> DirectedCase:
    return DirectedCase(op_name, a_bits, b_bits, tuple(rms), note)


def build_cases() -> List[DirectedCase]:
    return [
        case("fadd.d", QNAN, ONE, (RM_RNE,), "quiet NaN canonicalization"),
        case("fadd.d", SNAN, ONE, (RM_RNE,), "signaling NaN invalid"),
        case("fadd.d", POS_INF, NEG_INF, (RM_RNE,), "invalid +inf + -inf"),
        case("fadd.d", POS_ZERO, NEG_ZERO, ALL_RM, "zero-sign rule"),
        case("fadd.d", MAX_FINITE, MAX_FINITE, ALL_RM, "positive overflow"),
        case("fadd.d", ONE, HALF_ULP_AT_ONE, ALL_RM, "tie rounding at 1.0"),
        case("fadd.d", ONE, NEXT_HALF_ULP_AT_ONE, ALL_RM, "just-above-tie rounding"),
        case("fadd.d", MIN_NORMAL, MAX_SUB | (1 << 63), (RM_RNE,), "normal/subnormal boundary"),

        case("fsub.d", QNAN, ONE, (RM_RNE,), "quiet NaN canonicalization"),
        case("fsub.d", SNAN, ONE, (RM_RNE,), "signaling NaN invalid"),
        case("fsub.d", POS_INF, POS_INF, (RM_RNE,), "invalid inf - inf"),
        case("fsub.d", POS_ZERO, POS_ZERO, ALL_RM, "zero-sign rule for exact zero"),
        case("fsub.d", POS_ZERO, NEG_ZERO, ALL_RM, "zero-sign rule for +0 - -0"),
        case("fsub.d", MAX_FINITE, MAX_FINITE | (1 << 63), ALL_RM, "overflow after subtracting a negative"),
        case("fsub.d", ONE, HALF_ULP_AT_ONE, ALL_RM, "tie rounding at 1.0 - 0.5 ulp"),
        case("fsub.d", ONE, NEXT_HALF_ULP_AT_ONE, ALL_RM, "just-above-tie rounding"),

        case("fmul.d", QNAN, ONE, (RM_RNE,), "quiet NaN canonicalization"),
        case("fmul.d", SNAN, ONE, (RM_RNE,), "signaling NaN invalid"),
        case("fmul.d", POS_INF, POS_ZERO, (RM_RNE,), "invalid inf * 0"),
        case("fmul.d", POS_INF, TWO, (RM_RNE,), "inf propagation"),
        case("fmul.d", NEG_ZERO, TWO, (RM_RNE,), "signed zero"),
        case("fmul.d", MAX_FINITE, TWO, ALL_RM, "overflow under all rounding modes"),
        case("fmul.d", MIN_SUB, HALF, ALL_RM, "subnormal underflow"),
        case("fmul.d", 0x3FF8_0000_0000_0000, TWO, (RM_RNE,), "exact 1.5 * 2"),

        case("fdiv.d", QNAN, ONE, (RM_RNE,), "quiet NaN canonicalization"),
        case("fdiv.d", SNAN, ONE, (RM_RNE,), "signaling NaN invalid"),
        case("fdiv.d", POS_INF, POS_INF, (RM_RNE,), "invalid inf / inf"),
        case("fdiv.d", POS_ZERO, POS_ZERO, (RM_RNE,), "invalid 0 / 0"),
        case("fdiv.d", POS_INF, TWO, (RM_RNE,), "inf / finite"),
        case("fdiv.d", TWO, POS_INF, (RM_RNE,), "finite / inf"),
        case("fdiv.d", TWO, POS_ZERO, (RM_RNE,), "divide by zero"),
        case("fdiv.d", POS_ZERO, TWO, (RM_RNE,), "zero divided by finite"),
        case("fdiv.d", ONE, TWO, (RM_RNE,), "exact 1 / 2"),
        case("fdiv.d", ONE, THREE, ALL_RM, "inexact 1 / 3 rounding"),

        case("feq.d", QNAN, ONE, (RM_RNE,), "qNaN is quiet for feq"),
        case("feq.d", SNAN, ONE, (RM_RNE,), "sNaN invalid for feq"),
        case("feq.d", POS_ZERO, NEG_ZERO, (RM_RNE,), "+0 == -0"),
        case("feq.d", ONE, ONE, (RM_RNE,), "ordered equality"),
        case("feq.d", ONE, TWO, (RM_RNE,), "ordered inequality"),

        case("flt.d", QNAN, ONE, (RM_RNE,), "qNaN invalid for flt"),
        case("flt.d", SNAN, ONE, (RM_RNE,), "sNaN invalid for flt"),
        case("flt.d", POS_ZERO, NEG_ZERO, (RM_RNE,), "-0 is not less than +0"),
        case("flt.d", NEG_ONE, ONE, (RM_RNE,), "negative less than positive"),
        case("flt.d", TWO, ONE, (RM_RNE,), "ordered false compare"),

        case("fle.d", QNAN, ONE, (RM_RNE,), "qNaN invalid for fle"),
        case("fle.d", SNAN, ONE, (RM_RNE,), "sNaN invalid for fle"),
        case("fle.d", POS_ZERO, NEG_ZERO, (RM_RNE,), "+0 <= -0"),
        case("fle.d", ONE, ONE, (RM_RNE,), "ordered equality"),
        case("fle.d", TWO, ONE, (RM_RNE,), "ordered false compare"),

        case("fsgnj.d", ONE, NEG_ONE, (RM_RNE,), "copy sign from operand B"),
        case("fsgnj.d", QNAN, NEG_ONE, (RM_RNE,), "sign-injection preserves NaN payload"),

        case("fsgnjn.d", ONE, NEG_ONE, (RM_RNE,), "invert sign of operand B"),
        case("fsgnjn.d", QNAN, NEG_ONE, (RM_RNE,), "sign-inversion preserves NaN payload"),

        case("fsgnjx.d", ONE, NEG_ONE, (RM_RNE,), "xor signs"),
        case("fsgnjx.d", QNAN, NEG_ONE, (RM_RNE,), "sign-xor preserves NaN payload"),

        case("fcvt.w.d", QNAN, 0, (RM_RNE,), "NaN to int invalid"),
        case("fcvt.w.d", POS_INF, 0, (RM_RNE,), "+inf to int invalid"),
        case("fcvt.w.d", NEG_INF, 0, (RM_RNE,), "-inf to int invalid"),
        case("fcvt.w.d", 0x3FF8_0000_0000_0000, 0, ALL_RM, "1.5 rounding modes"),
        case("fcvt.w.d", NEG_HALF, 0, ALL_RM, "-0.5 rounding modes"),
        case("fcvt.w.d", int_to_fp64_bits(INT32_MAX), 0, (RM_RNE,), "largest exact signed int"),
        case("fcvt.w.d", int_to_fp64_bits(1 << 31), 0, (RM_RNE,), "positive overflow to int32"),
        case("fcvt.w.d", int_to_fp64_bits(-(1 << 31)), 0, (RM_RNE,), "most negative exact signed int"),

        case("fcvt.wu.d", QNAN, 0, (RM_RNE,), "NaN to uint invalid"),
        case("fcvt.wu.d", POS_INF, 0, (RM_RNE,), "+inf to uint invalid"),
        case("fcvt.wu.d", NEG_INF, 0, (RM_RNE,), "-inf to uint invalid"),
        case("fcvt.wu.d", HALF, 0, ALL_RM, "0.5 rounding modes"),
        case("fcvt.wu.d", 0xBFD0_0000_0000_0000, 0, ALL_RM, "-0.25 unsigned rounding"),
        case("fcvt.wu.d", int_to_fp64_bits(UINT32_MAX), 0, (RM_RNE,), "largest exact uint32"),
        case("fcvt.wu.d", int_to_fp64_bits(1 << 32), 0, (RM_RNE,), "positive overflow to uint32"),

        case("fcvt.d.w", 0x0000_0000, 0, (RM_RNE,), "zero int to fp64"),
        case("fcvt.d.w", 0x0000_0001, 0, (RM_RNE,), "positive int to fp64"),
        case("fcvt.d.w", 0xFFFF_FFFF, 0, (RM_RNE,), "-1 to fp64"),
        case("fcvt.d.w", 0x7FFF_FFFF, 0, (RM_RNE,), "INT32_MAX to fp64"),
        case("fcvt.d.w", 0x8000_0000, 0, (RM_RNE,), "INT32_MIN to fp64"),

        case("fcvt.d.wu", 0x0000_0000, 0, (RM_RNE,), "zero uint to fp64"),
        case("fcvt.d.wu", 0x0000_0001, 0, (RM_RNE,), "positive uint to fp64"),
        case("fcvt.d.wu", 0x8000_0000, 0, (RM_RNE,), "high-bit uint to fp64"),
        case("fcvt.d.wu", UINT32_MAX, 0, (RM_RNE,), "UINT32_MAX to fp64"),

        case("fclass.d", NEG_INF, 0, (RM_RNE,), "class -inf"),
        case("fclass.d", MAX_FINITE | (1 << 63), 0, (RM_RNE,), "class negative normal"),
        case("fclass.d", MAX_SUB | (1 << 63), 0, (RM_RNE,), "class negative subnormal"),
        case("fclass.d", NEG_ZERO, 0, (RM_RNE,), "class -0"),
        case("fclass.d", POS_ZERO, 0, (RM_RNE,), "class +0"),
        case("fclass.d", MIN_SUB, 0, (RM_RNE,), "class positive subnormal"),
        case("fclass.d", ONE, 0, (RM_RNE,), "class positive normal"),
        case("fclass.d", POS_INF, 0, (RM_RNE,), "class +inf"),
        case("fclass.d", SNAN, 0, (RM_RNE,), "class sNaN"),
        case("fclass.d", QNAN, 0, (RM_RNE,), "class qNaN"),

        case("fmin.d", QNAN, ONE, (RM_RNE,), "single qNaN returns numeric operand"),
        case("fmin.d", SNAN, ONE, (RM_RNE,), "single sNaN returns numeric operand with NV"),
        case("fmin.d", QNAN, QNAN, (RM_RNE,), "double NaN returns canonical NaN"),
        case("fmin.d", NEG_ZERO, POS_ZERO, (RM_RNE,), "min prefers -0"),
        case("fmin.d", ONE, TWO, (RM_RNE,), "ordered minimum"),

        case("fmax.d", QNAN, ONE, (RM_RNE,), "single qNaN returns numeric operand"),
        case("fmax.d", SNAN, ONE, (RM_RNE,), "single sNaN returns numeric operand with NV"),
        case("fmax.d", QNAN, QNAN, (RM_RNE,), "double NaN returns canonical NaN"),
        case("fmax.d", NEG_ZERO, POS_ZERO, (RM_RNE,), "max prefers +0"),
        case("fmax.d", ONE, TWO, (RM_RNE,), "ordered maximum"),
    ]


def parse_ops(text: str) -> List[str]:
    if text.strip().lower() == "all":
        return list(OP_SPECS.keys())
    ops = [part.strip() for part in text.split(",") if part.strip()]
    unknown = [op for op in ops if op not in OP_SPECS]
    if unknown:
        raise ValueError(f"unknown ops: {', '.join(unknown)}")
    return ops


def generate_vectors(cases: Iterable[DirectedCase], selected_ops: Sequence[str]) -> List[str]:
    lines: List[str] = []
    selected = set(selected_ops)
    for item in cases:
        if item.op_name not in selected:
            continue
        spec = OP_SPECS[item.op_name]
        for rm in item.rms:
            exp_res, exp_flags = oracle_case(item.op_name, item.a_bits, item.b_bits, rm)
            lines.append(format_vector(item.a_bits, item.b_bits, exp_res, exp_flags, rm, spec.sel))
    return lines


def generate_manifest(cases: Iterable[DirectedCase], selected_ops: Sequence[str]) -> List[str]:
    lines: List[str] = []
    selected = set(selected_ops)
    index = 1
    for item in cases:
        if item.op_name not in selected:
            continue
        for rm in item.rms:
            exp_res, exp_flags = oracle_case(item.op_name, item.a_bits, item.b_bits, rm)
            lines.append(
                f"{index:03d} {item.op_name} rm={RM_NAMES[rm]} "
                f"a={item.a_bits & ((1 << 64) - 1):016x} "
                f"b={item.b_bits & ((1 << 64) - 1):016x} "
                f"exp={exp_res & ((1 << 64) - 1):016x} flags={exp_flags:02x} "
                f"note={item.note}"
            )
            index += 1
    return lines


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate directed RISC-V vectors for all supported ops")
    parser.add_argument("--ops", default="all", help="comma-separated op list or 'all'")
    parser.add_argument("--output", default="verify/riscv_directed_vectors.txt", help="vector output path")
    parser.add_argument("--manifest", default="verify/riscv_directed_manifest.txt", help="manifest output path")
    args = parser.parse_args()

    selected_ops = parse_ops(args.ops)
    cases = build_cases()
    vector_lines = generate_vectors(cases, selected_ops)
    manifest_lines = generate_manifest(cases, selected_ops)

    output_path = Path(args.output)
    manifest_path = Path(args.manifest)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(vector_lines) + "\n", encoding="ascii")
    manifest_path.write_text("\n".join(manifest_lines) + "\n", encoding="ascii")

    print(f"wrote {len(vector_lines)} directed vectors to {output_path}")
    print(f"wrote {len(manifest_lines)} manifest lines to {manifest_path}")
    print(f"ops: {', '.join(selected_ops)}")


if __name__ == "__main__":
    main()
