#!/usr/bin/env python3
"""Generate directed FP64 add vectors that target RISC-V boundary semantics."""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List

from riscv_adapter import (
    CANONICAL_NAN_D,
    FADD_D_SEL,
    RM_NAMES,
    RM_RDN,
    RM_RMM,
    RM_RNE,
    RM_RTZ,
    RM_RUP,
    fadd_oracle,
    format_vector,
)


ALL_RM = [RM_RNE, RM_RTZ, RM_RDN, RM_RUP, RM_RMM]

POS_ZERO = 0x0000_0000_0000_0000
NEG_ZERO = 0x8000_0000_0000_0000
POS_INF = 0x7FF0_0000_0000_0000
NEG_INF = 0xFFF0_0000_0000_0000
MAX_FINITE = 0x7FEF_FFFF_FFFF_FFFF
MIN_SUB = 0x0000_0000_0000_0001
MAX_SUB = 0x000F_FFFF_FFFF_FFFF
MIN_NORMAL = 0x0010_0000_0000_0000
ONE = 0x3FF0_0000_0000_0000
NEG_ONE = 0xBFF0_0000_0000_0000
QNAN = CANONICAL_NAN_D
SNAN = 0x7FF0_0000_0000_0001
HALF_ULP_AT_ONE = 0x3CA0_0000_0000_0000
PREV_HALF_ULP_AT_ONE = HALF_ULP_AT_ONE - 1
NEXT_HALF_ULP_AT_ONE = HALF_ULP_AT_ONE + 1
NEG_HALF_ULP_AT_ONE = HALF_ULP_AT_ONE | (1 << 63)
NEG_PREV_HALF_ULP_AT_ONE = PREV_HALF_ULP_AT_ONE | (1 << 63)
NEG_NEXT_HALF_ULP_AT_ONE = NEXT_HALF_ULP_AT_ONE | (1 << 63)


@dataclass(frozen=True)
class DirectedCase:
    name: str
    a_bits: int
    b_bits: int
    rms: List[int]
    note: str


def build_cases() -> List[DirectedCase]:
    return [
        DirectedCase("qnan_plus_one", QNAN, ONE, [RM_RNE], "quiet NaN should return canonical NaN without NV"),
        DirectedCase("snan_plus_one", SNAN, ONE, [RM_RNE], "signaling NaN should return canonical NaN with NV"),
        DirectedCase("pos_inf_plus_neg_inf", POS_INF, NEG_INF, [RM_RNE], "invalid inf + (-inf) must raise NV"),
        DirectedCase("pos_inf_plus_one", POS_INF, ONE, [RM_RNE], "infinite operand should pass through without flags"),
        DirectedCase("pos_zero_plus_neg_zero", POS_ZERO, NEG_ZERO, ALL_RM, "exact zero sign depends on rounding mode for opposite-signed zeros"),
        DirectedCase("min_sub_plus_neg_min_sub", MIN_SUB, MIN_SUB | (1 << 63), ALL_RM, "exact cancellation should hit signed-zero rule"),
        DirectedCase("min_normal_minus_max_sub", MIN_NORMAL, MAX_SUB | (1 << 63), [RM_RNE], "normal/subnormal boundary should produce +min_sub"),
        DirectedCase("neg_min_normal_plus_max_sub", MIN_NORMAL | (1 << 63), MAX_SUB, [RM_RNE], "normal/subnormal boundary should produce -min_sub"),
        DirectedCase("max_finite_plus_max_finite", MAX_FINITE, MAX_FINITE, ALL_RM, "positive overflow should respect rm-specific saturation"),
        DirectedCase("neg_max_finite_plus_neg_max_finite", MAX_FINITE | (1 << 63), MAX_FINITE | (1 << 63), ALL_RM, "negative overflow should respect rm-specific saturation"),
        DirectedCase("one_plus_prev_half_ulp", ONE, PREV_HALF_ULP_AT_ONE, ALL_RM, "just below tie at 0.5 ulp around 1.0"),
        DirectedCase("one_plus_half_ulp", ONE, HALF_ULP_AT_ONE, ALL_RM, "exact tie at 0.5 ulp around 1.0"),
        DirectedCase("one_plus_next_half_ulp", ONE, NEXT_HALF_ULP_AT_ONE, ALL_RM, "just above tie at 0.5 ulp around 1.0"),
        DirectedCase("neg_one_plus_neg_prev_half_ulp", NEG_ONE, NEG_PREV_HALF_ULP_AT_ONE, ALL_RM, "negative just-below-tie rounding stress"),
        DirectedCase("neg_one_plus_neg_half_ulp", NEG_ONE, NEG_HALF_ULP_AT_ONE, ALL_RM, "negative exact tie rounding stress"),
        DirectedCase("neg_one_plus_neg_next_half_ulp", NEG_ONE, NEG_NEXT_HALF_ULP_AT_ONE, ALL_RM, "negative just-above-tie rounding stress"),
        DirectedCase("one_plus_min_sub", ONE, MIN_SUB, ALL_RM, "tiny addend absorbed by 1.0, but directed modes still differ in intent"),
        DirectedCase("neg_one_plus_neg_min_sub", NEG_ONE, MIN_SUB | (1 << 63), ALL_RM, "tiny negative addend absorbed by -1.0"),
    ]


def generate_lines(cases: Iterable[DirectedCase]) -> List[str]:
    lines: List[str] = []
    for case in cases:
        for rm in case.rms:
            res_bits, flags = fadd_oracle(case.a_bits, case.b_bits, rm)
            lines.append(format_vector(case.a_bits, case.b_bits, res_bits, flags, rm, FADD_D_SEL))
    return lines


def generate_manifest(cases: Iterable[DirectedCase]) -> List[str]:
    lines: List[str] = []
    index = 1
    for case in cases:
        for rm in case.rms:
            res_bits, flags = fadd_oracle(case.a_bits, case.b_bits, rm)
            lines.append(
                f"{index:03d} {case.name} rm={RM_NAMES[rm]} "
                f"a={case.a_bits:016x} b={case.b_bits:016x} "
                f"exp={res_bits:016x} flags={flags:02x} note={case.note}"
            )
            index += 1
    return lines


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate directed FP64 add vectors")
    parser.add_argument(
        "--output",
        default="verify/fadd_directed_vectors.txt",
        help="vector output path (default: verify/fadd_directed_vectors.txt)",
    )
    parser.add_argument(
        "--manifest",
        default="verify/fadd_directed_manifest.txt",
        help="human-readable manifest path (default: verify/fadd_directed_manifest.txt)",
    )
    args = parser.parse_args()

    cases = build_cases()
    vector_lines = generate_lines(cases)
    manifest_lines = generate_manifest(cases)

    output_path = Path(args.output)
    manifest_path = Path(args.manifest)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    manifest_path.parent.mkdir(parents=True, exist_ok=True)

    output_path.write_text("\n".join(vector_lines) + "\n", encoding="ascii")
    manifest_path.write_text("\n".join(manifest_lines) + "\n", encoding="ascii")

    print(f"wrote {len(vector_lines)} directed vectors to {output_path}")
    print(f"wrote {len(manifest_lines)} manifest lines to {manifest_path}")


if __name__ == "__main__":
    main()
