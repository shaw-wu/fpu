#!/usr/bin/env python3
"""RISC-V semantic adapters and bit-level oracle helpers for FP64 tests."""

from __future__ import annotations

from dataclasses import dataclass
from typing import Callable, Dict, Optional, Tuple


SIGN_MASK = 0x8000_0000_0000_0000
EXP_MASK = 0x7FF0_0000_0000_0000
FRAC_MASK = 0x000F_FFFF_FFFF_FFFF
UINT64_MASK = (1 << 64) - 1

POS_ZERO = 0x0000_0000_0000_0000
NEG_ZERO = 0x8000_0000_0000_0000
POS_INF = 0x7FF0_0000_0000_0000
NEG_INF = 0xFFF0_0000_0000_0000
MAX_FINITE = 0x7FEF_FFFF_FFFF_FFFF
CANONICAL_NAN_D = 0x7FF8_0000_0000_0000

INT32_MIN = -(1 << 31)
INT32_MAX = (1 << 31) - 1
UINT32_MAX = (1 << 32) - 1

FADD_D_SEL = 0x00
FSUB_D_SEL = 0x01
FMUL_D_SEL = 0x02
FDIV_D_SEL = 0x03
FEQ_D_SEL = 0x04
FLT_D_SEL = 0x05
FLE_D_SEL = 0x06
FSGNJ_D_SEL = 0x07
FSGNJN_D_SEL = 0x08
FSGNJX_D_SEL = 0x09
FCVT_W_D_SEL = 0x0A
FCVT_WU_D_SEL = 0x0B
FCVT_D_W_SEL = 0x0C
FCVT_D_WU_SEL = 0x0D
FCLASS_D_SEL = 0x0E
FMIN_D_SEL = 0x0F
FMAX_D_SEL = 0x10

RM_RNE = 0
RM_RTZ = 1
RM_RDN = 2
RM_RUP = 3
RM_RMM = 4
ALL_RM = (RM_RNE, RM_RTZ, RM_RDN, RM_RUP, RM_RMM)

RM_NAMES = {
    RM_RNE: "RNE",
    RM_RTZ: "RTZ",
    RM_RDN: "RDN",
    RM_RUP: "RUP",
    RM_RMM: "RMM",
}

TF_RM_FLAGS = {
    RM_RNE: "-rnear_even",
    RM_RTZ: "-rminMag",
    RM_RDN: "-rmin",
    RM_RUP: "-rmax",
    RM_RMM: "-rnear_maxMag",
}

SPECIAL_FP64_VALUES = (
    POS_ZERO,
    NEG_ZERO,
    POS_INF,
    NEG_INF,
    CANONICAL_NAN_D,
    0x7FF0_0000_0000_0001,  # sNaN
    0x7FFF_FFFF_FFFF_FFFF,  # qNaN with max payload
    0xFFF0_0000_0000_0001,  # negative sNaN
    0xFFFF_FFFF_FFFF_FFFF,  # negative qNaN
    0x0000_0000_0000_0001,  # min subnormal
    0x8000_0000_0000_0001,
    0x000F_FFFF_FFFF_FFFF,  # max subnormal
    0x800F_FFFF_FFFF_FFFF,
    0x0010_0000_0000_0000,  # min normal
    0x8010_0000_0000_0000,
    MAX_FINITE,
    MAX_FINITE | SIGN_MASK,
    0x3FF0_0000_0000_0000,  # 1.0
    0xBFF0_0000_0000_0000,  # -1.0
    0x4000_0000_0000_0000,  # 2.0
    0xC000_0000_0000_0000,  # -2.0
    0x3CA0_0000_0000_0000,  # 0.5 ulp at 1.0
    0xBCA0_0000_0000_0000,
)

SPECIAL_INT32_VALUES = (
    0x0000_0000,
    0x0000_0001,
    0xFFFF_FFFF,
    0x7FFF_FFFF,
    0x8000_0000,
    0xFFFF_0000,
    0x0000_FFFF,
    0x4000_0000,
)


@dataclass(frozen=True)
class Fp64:
    bits: int
    sign: int
    exp_field: int
    frac_field: int
    is_nan: bool
    is_snan: bool
    is_qnan: bool
    is_inf: bool
    is_zero: bool
    is_subnormal: bool
    is_normal: bool
    mant: int
    exp2: Optional[int]


@dataclass(frozen=True)
class OpSpec:
    name: str
    sel: int
    arity: str
    rm_sensitive: bool
    oracle: Callable[[int, int, int], Tuple[int, int]]
    testfloat_func: Optional[str] = None
    testfloat_exact: bool = False


def decode_fp64(bits: int) -> Fp64:
    bits &= UINT64_MASK
    sign = (bits >> 63) & 1
    exp_field = (bits >> 52) & 0x7FF
    frac_field = bits & FRAC_MASK

    is_nan = exp_field == 0x7FF and frac_field != 0
    is_snan = is_nan and ((frac_field >> 51) & 1) == 0
    is_qnan = is_nan and not is_snan
    is_inf = exp_field == 0x7FF and frac_field == 0
    is_zero = exp_field == 0 and frac_field == 0
    is_subnormal = exp_field == 0 and frac_field != 0
    is_normal = exp_field not in (0, 0x7FF)

    if is_normal:
        mant = (1 << 52) | frac_field
        exp2 = exp_field - 1023 - 52
    elif is_subnormal:
        mant = frac_field
        exp2 = -1074
    else:
        mant = 0
        exp2 = None

    return Fp64(
        bits=bits,
        sign=sign,
        exp_field=exp_field,
        frac_field=frac_field,
        is_nan=is_nan,
        is_snan=is_snan,
        is_qnan=is_qnan,
        is_inf=is_inf,
        is_zero=is_zero,
        is_subnormal=is_subnormal,
        is_normal=is_normal,
        mant=mant,
        exp2=exp2,
    )


def is_nan_bits(bits: int) -> bool:
    return decode_fp64(bits).is_nan


def pack_fflags(*, nv: bool = False, dz: bool = False, of: bool = False, uf: bool = False, nx: bool = False) -> int:
    return (int(nv) << 4) | (int(dz) << 3) | (int(of) << 2) | (int(uf) << 1) | int(nx)


def pack_inf(sign: int) -> int:
    return (sign << 63) | POS_INF


def pack_max_finite(sign: int) -> int:
    return (sign << 63) | MAX_FINITE


def result32_to_fresult(value: int) -> int:
    return value & UINT32_MAX


def int32_from_bits(bits: int) -> int:
    bits &= UINT32_MAX
    return bits if bits < (1 << 31) else bits - (1 << 32)


def compare_rational_to_pow2(num: int, den: int, exp2: int, target_exp: int) -> int:
    shift = exp2 - target_exp
    if shift >= 0:
        lhs = num << shift
        rhs = den
    else:
        lhs = num
        rhs = den << (-shift)

    if lhs < rhs:
        return -1
    if lhs > rhs:
        return 1
    return 0


def divrem_scaled(num: int, den: int, shift: int) -> Tuple[int, int, int]:
    if shift >= 0:
        scaled_num = num << shift
        quotient, remainder = divmod(scaled_num, den)
        return quotient, remainder, den

    scaled_den = den << (-shift)
    quotient, remainder = divmod(num, scaled_den)
    return quotient, remainder, scaled_den


def should_round_up(rm: int, sign: int, lsb: int, numerator: int, denominator: int) -> bool:
    if numerator == 0:
        return False

    twice_num = numerator << 1
    gt_half = twice_num > denominator
    eq_half = twice_num == denominator

    if rm == RM_RNE:
        return gt_half or (eq_half and lsb == 1)
    if rm == RM_RTZ:
        return False
    if rm == RM_RDN:
        return sign == 1
    if rm == RM_RUP:
        return sign == 0
    if rm == RM_RMM:
        return gt_half or eq_half

    raise ValueError(f"unsupported rounding mode: {rm}")


def overflow_result(sign: int, rm: int) -> int:
    if rm == RM_RTZ:
        return pack_max_finite(sign)
    if rm == RM_RDN:
        return pack_inf(sign) if sign else pack_max_finite(0)
    if rm == RM_RUP:
        return pack_max_finite(1) if sign else pack_inf(0)
    if rm in (RM_RNE, RM_RMM):
        return pack_inf(sign)
    raise ValueError(f"unsupported rounding mode: {rm}")


def round_fp64_from_dyadic(sign: int, abs_mant: int, exp2: int, rm: int) -> Tuple[int, int]:
    return round_fp64_from_rational(sign, abs_mant, 1, exp2, rm)


def round_fp64_from_rational(sign: int, num: int, den: int, exp2: int, rm: int) -> Tuple[int, int]:
    """Round sign * (num / den) * 2**exp2 to binary64 with tininess-after-rounding."""
    assert num > 0
    assert den > 0

    unbiased_exp = num.bit_length() - den.bit_length() + exp2
    while compare_rational_to_pow2(num, den, exp2, unbiased_exp) < 0:
        unbiased_exp -= 1
    while compare_rational_to_pow2(num, den, exp2, unbiased_exp + 1) >= 0:
        unbiased_exp += 1

    if unbiased_exp >= -1022:
        shift = exp2 + 52 - unbiased_exp
        quotient, remainder, half_den = divrem_scaled(num, den, shift)
        rounded = quotient + int(should_round_up(rm, sign, quotient & 1, remainder, half_den))
        nx = remainder != 0

        if rounded == (1 << 53):
            rounded >>= 1
            unbiased_exp += 1

        if unbiased_exp > 1023:
            return overflow_result(sign, rm), pack_fflags(of=True, nx=True)

        exp_field = unbiased_exp + 1023
        frac_field = rounded - (1 << 52)
        bits = (sign << 63) | (exp_field << 52) | frac_field
        return bits, pack_fflags(nx=nx)

    shift = exp2 + 1074
    quotient, remainder, half_den = divrem_scaled(num, den, shift)
    rounded = quotient + int(should_round_up(rm, sign, quotient & 1, remainder, half_den))
    nx = remainder != 0

    if rounded >= (1 << 52):
        bits = (sign << 63) | (1 << 52)
        return bits, pack_fflags(nx=nx)

    bits = (sign << 63) | rounded
    return bits, pack_fflags(uf=nx, nx=nx)


def exact_zero_sign_addsub(rm: int, sign_a: int, sign_b: int) -> int:
    if sign_a == sign_b:
        return sign_a
    return 1 if rm == RM_RDN else 0


def compare_ordered(a: Fp64, b: Fp64) -> int:
    if a.is_zero and b.is_zero:
        return 0
    if a.bits == b.bits:
        return 0
    if a.sign != b.sign:
        return -1 if a.sign else 1
    if a.sign == 0:
        return -1 if a.bits < b.bits else 1
    return -1 if a.bits > b.bits else 1


def fadd_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)

    if a.is_nan or b.is_nan:
        return CANONICAL_NAN_D, pack_fflags(nv=a.is_snan or b.is_snan)

    if a.is_inf and b.is_inf and a.sign != b.sign:
        return CANONICAL_NAN_D, pack_fflags(nv=True)

    if a.is_inf:
        return pack_inf(a.sign), 0
    if b.is_inf:
        return pack_inf(b.sign), 0

    if a.is_zero and b.is_zero:
        sign = exact_zero_sign_addsub(rm, a.sign, b.sign)
        return sign << 63, 0

    shared_exp = min(
        a.exp2 if not a.is_zero else b.exp2,
        b.exp2 if not b.is_zero else a.exp2,
    )
    acc = 0
    if not a.is_zero:
        assert a.exp2 is not None
        acc += ((-1) if a.sign else 1) * (a.mant << (a.exp2 - shared_exp))
    if not b.is_zero:
        assert b.exp2 is not None
        acc += ((-1) if b.sign else 1) * (b.mant << (b.exp2 - shared_exp))

    if acc == 0:
        return ((1 << 63) if rm == RM_RDN else 0), 0

    sign = 1 if acc < 0 else 0
    return round_fp64_from_dyadic(sign, abs(acc), shared_exp, rm)


def fsub_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    return fadd_oracle(a_bits, b_bits ^ SIGN_MASK, rm)


def fmul_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)

    if a.is_nan or b.is_nan:
        return CANONICAL_NAN_D, pack_fflags(nv=a.is_snan or b.is_snan)

    if (a.is_inf and b.is_zero) or (b.is_inf and a.is_zero):
        return CANONICAL_NAN_D, pack_fflags(nv=True)

    sign = a.sign ^ b.sign

    if a.is_inf or b.is_inf:
        return pack_inf(sign), 0

    if a.is_zero or b.is_zero:
        return sign << 63, 0

    assert a.exp2 is not None
    assert b.exp2 is not None
    return round_fp64_from_dyadic(sign, a.mant * b.mant, a.exp2 + b.exp2, rm)


def fdiv_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)

    if a.is_nan or b.is_nan:
        return CANONICAL_NAN_D, pack_fflags(nv=a.is_snan or b.is_snan)

    if (a.is_inf and b.is_inf) or (a.is_zero and b.is_zero):
        return CANONICAL_NAN_D, pack_fflags(nv=True)

    sign = a.sign ^ b.sign

    if a.is_inf:
        return pack_inf(sign), 0
    if b.is_inf:
        return sign << 63, 0
    if b.is_zero:
        return pack_inf(sign), pack_fflags(dz=not a.is_zero)
    if a.is_zero:
        return sign << 63, 0

    assert a.exp2 is not None
    assert b.exp2 is not None
    return round_fp64_from_rational(sign, a.mant, b.mant, a.exp2 - b.exp2, rm)


def feq_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)
    result = 0

    if not (a.is_nan or b.is_nan):
        result = 1 if (a.bits == b.bits or (a.is_zero and b.is_zero)) else 0

    return result, pack_fflags(nv=a.is_snan or b.is_snan)


def flt_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)
    if a.is_nan or b.is_nan:
        return 0, pack_fflags(nv=True)
    return int(compare_ordered(a, b) < 0), 0


def fle_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)
    if a.is_nan or b.is_nan:
        return 0, pack_fflags(nv=True)
    return int(compare_ordered(a, b) <= 0), 0


def fsgnj_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    return (a_bits & ~SIGN_MASK) | (b_bits & SIGN_MASK), 0


def fsgnjn_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    return (a_bits & ~SIGN_MASK) | ((~b_bits) & SIGN_MASK), 0


def fsgnjx_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    return (a_bits & ~SIGN_MASK) | ((a_bits ^ b_bits) & SIGN_MASK), 0


def fclass_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del b_bits, rm
    a = decode_fp64(a_bits)
    if a.is_inf and a.sign:
        return 0x001, 0
    if a.is_normal and a.sign:
        return 0x002, 0
    if a.is_subnormal and a.sign:
        return 0x004, 0
    if a.is_zero and a.sign:
        return 0x008, 0
    if a.is_zero and not a.sign:
        return 0x010, 0
    if a.is_subnormal and not a.sign:
        return 0x020, 0
    if a.is_normal and not a.sign:
        return 0x040, 0
    if a.is_inf and not a.sign:
        return 0x080, 0
    if a.is_snan:
        return 0x100, 0
    if a.is_qnan:
        return 0x200, 0
    return 0, 0


def fmin_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)
    any_snan = a.is_snan or b.is_snan

    if a.is_nan and b.is_nan:
        return CANONICAL_NAN_D, pack_fflags(nv=any_snan)
    if a.is_nan:
        return b.bits, pack_fflags(nv=any_snan)
    if b.is_nan:
        return a.bits, pack_fflags(nv=any_snan)
    if a.is_zero and b.is_zero:
        return NEG_ZERO, pack_fflags(nv=any_snan)

    return (a.bits if compare_ordered(a, b) <= 0 else b.bits), pack_fflags(nv=any_snan)


def fmax_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del rm
    a = decode_fp64(a_bits)
    b = decode_fp64(b_bits)
    any_snan = a.is_snan or b.is_snan

    if a.is_nan and b.is_nan:
        return CANONICAL_NAN_D, pack_fflags(nv=any_snan)
    if a.is_nan:
        return b.bits, pack_fflags(nv=any_snan)
    if b.is_nan:
        return a.bits, pack_fflags(nv=any_snan)
    if a.is_zero and b.is_zero:
        return POS_ZERO, pack_fflags(nv=any_snan)

    return (a.bits if compare_ordered(a, b) >= 0 else b.bits), pack_fflags(nv=any_snan)


def round_signed_integer(sign: int, magnitude_num: int, magnitude_den: int, rm: int) -> Tuple[int, bool]:
    int_part, remainder = divmod(magnitude_num, magnitude_den)
    rounded_mag = int_part + int(should_round_up(rm, sign, int_part & 1, remainder, magnitude_den))
    rounded_val = -rounded_mag if sign else rounded_mag
    return rounded_val, remainder != 0


def fcvt_w_d_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del b_bits
    a = decode_fp64(a_bits)

    if a.is_nan:
        return result32_to_fresult(INT32_MAX), pack_fflags(nv=True)
    if a.is_inf:
        sat = INT32_MIN if a.sign else INT32_MAX
        return result32_to_fresult(sat), pack_fflags(nv=True)
    if a.is_zero:
        return 0, 0

    assert a.exp2 is not None
    if a.exp2 >= 0:
        num = a.mant << a.exp2
        den = 1
    else:
        num = a.mant
        den = 1 << (-a.exp2)

    rounded_val, nx = round_signed_integer(a.sign, num, den, rm)
    if rounded_val < INT32_MIN:
        return result32_to_fresult(INT32_MIN), pack_fflags(nv=True)
    if rounded_val > INT32_MAX:
        return result32_to_fresult(INT32_MAX), pack_fflags(nv=True)
    return result32_to_fresult(rounded_val), pack_fflags(nx=nx)


def fcvt_wu_d_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del b_bits
    a = decode_fp64(a_bits)

    if a.is_nan:
        return result32_to_fresult(UINT32_MAX), pack_fflags(nv=True)
    if a.is_inf:
        sat = 0 if a.sign else UINT32_MAX
        return result32_to_fresult(sat), pack_fflags(nv=True)
    if a.is_zero:
        return 0, 0

    assert a.exp2 is not None
    if a.exp2 >= 0:
        num = a.mant << a.exp2
        den = 1
    else:
        num = a.mant
        den = 1 << (-a.exp2)

    rounded_val, nx = round_signed_integer(a.sign, num, den, rm)
    if rounded_val < 0:
        return result32_to_fresult(0), pack_fflags(nv=rounded_val != 0)
    if rounded_val > UINT32_MAX:
        return result32_to_fresult(UINT32_MAX), pack_fflags(nv=True)
    return result32_to_fresult(rounded_val), pack_fflags(nx=nx)


def int_to_fp64_bits(value: int) -> int:
    if value == 0:
        return POS_ZERO
    sign = 1 if value < 0 else 0
    magnitude = -value if value < 0 else value
    top_bit = magnitude.bit_length() - 1
    exp_field = top_bit + 1023
    frac_field = (magnitude << (52 - top_bit)) & FRAC_MASK
    return (sign << 63) | (exp_field << 52) | frac_field


def fcvt_d_w_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del b_bits, rm
    return int_to_fp64_bits(int32_from_bits(a_bits & UINT32_MAX)), 0


def fcvt_d_wu_oracle(a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    del b_bits, rm
    return int_to_fp64_bits(a_bits & UINT32_MAX), 0


def adapt_testfloat_float_result(raw_res_bits: int, raw_flags: int) -> Tuple[int, int]:
    if is_nan_bits(raw_res_bits):
        return CANONICAL_NAN_D, raw_flags & 0x1F
    return raw_res_bits & UINT64_MASK, raw_flags & 0x1F


def adapt_testfloat_case(op_name: str, raw_res_bits: int, raw_flags: int) -> Tuple[int, int]:
    if op_name in {"fadd.d", "fsub.d", "fmul.d", "fdiv.d"}:
        return adapt_testfloat_float_result(raw_res_bits, raw_flags)
    if op_name in {"feq.d", "flt.d", "fle.d"}:
        return raw_res_bits & 1, raw_flags & 0x1F
    if op_name in {"fcvt.w.d", "fcvt.wu.d"}:
        return result32_to_fresult(raw_res_bits), raw_flags & 0x1F
    if op_name in {"fcvt.d.w", "fcvt.d.wu"}:
        return raw_res_bits & UINT64_MASK, raw_flags & 0x1F
    raise ValueError(f"no testfloat adaptation for op {op_name}")


def adapt_testfloat_result_fadd(a_bits: int, b_bits: int, raw_res_bits: int, raw_flags: int) -> Tuple[int, int]:
    del a_bits, b_bits
    return adapt_testfloat_float_result(raw_res_bits, raw_flags)


def oracle_case(op_name: str, a_bits: int, b_bits: int, rm: int) -> Tuple[int, int]:
    return OP_SPECS[op_name].oracle(a_bits, b_bits, rm)


def format_vector(a_bits: int, b_bits: int, res_bits: int, flags: int, rm: int, sel: int) -> str:
    return f"{a_bits & UINT64_MASK:016x} {b_bits & UINT64_MASK:016x} {res_bits & UINT64_MASK:016x} {flags & 0x1F:02x} {rm & 0x7:02x} {sel & 0x1F:02x}"


OP_SPECS: Dict[str, OpSpec] = {
    "fadd.d": OpSpec("fadd.d", FADD_D_SEL, "binary_fp", True, fadd_oracle, "f64_add"),
    "fsub.d": OpSpec("fsub.d", FSUB_D_SEL, "binary_fp", True, fsub_oracle, "f64_sub"),
    "fmul.d": OpSpec("fmul.d", FMUL_D_SEL, "binary_fp", True, fmul_oracle, "f64_mul"),
    "fdiv.d": OpSpec("fdiv.d", FDIV_D_SEL, "binary_fp", True, fdiv_oracle, "f64_div"),
    "feq.d": OpSpec("feq.d", FEQ_D_SEL, "binary_fp", False, feq_oracle, "f64_eq"),
    "flt.d": OpSpec("flt.d", FLT_D_SEL, "binary_fp", False, flt_oracle, "f64_lt"),
    "fle.d": OpSpec("fle.d", FLE_D_SEL, "binary_fp", False, fle_oracle, "f64_le"),
    "fsgnj.d": OpSpec("fsgnj.d", FSGNJ_D_SEL, "binary_fp", False, fsgnj_oracle),
    "fsgnjn.d": OpSpec("fsgnjn.d", FSGNJN_D_SEL, "binary_fp", False, fsgnjn_oracle),
    "fsgnjx.d": OpSpec("fsgnjx.d", FSGNJX_D_SEL, "binary_fp", False, fsgnjx_oracle),
    "fcvt.w.d": OpSpec("fcvt.w.d", FCVT_W_D_SEL, "unary_fp", True, fcvt_w_d_oracle, "f64_to_i32", True),
    "fcvt.wu.d": OpSpec("fcvt.wu.d", FCVT_WU_D_SEL, "unary_fp", True, fcvt_wu_d_oracle, "f64_to_ui32", True),
    "fcvt.d.w": OpSpec("fcvt.d.w", FCVT_D_W_SEL, "unary_int", False, fcvt_d_w_oracle, "i32_to_f64"),
    "fcvt.d.wu": OpSpec("fcvt.d.wu", FCVT_D_WU_SEL, "unary_int", False, fcvt_d_wu_oracle, "ui32_to_f64"),
    "fclass.d": OpSpec("fclass.d", FCLASS_D_SEL, "unary_fp", False, fclass_oracle),
    "fmin.d": OpSpec("fmin.d", FMIN_D_SEL, "binary_fp", False, fmin_oracle),
    "fmax.d": OpSpec("fmax.d", FMAX_D_SEL, "binary_fp", False, fmax_oracle),
}
