# RISC-V Verification

This directory now preserves a repeatable verification flow for **all currently
supported FP64 operations** in this repository, not just `fadd.d`.

## Scope

Covered operations:

- `fadd.d`
- `fsub.d`
- `fmul.d`
- `fdiv.d`
- `feq.d`
- `flt.d`
- `fle.d`
- `fsgnj.d`
- `fsgnjn.d`
- `fsgnjx.d`
- `fcvt.w.d`
- `fcvt.wu.d`
- `fcvt.d.w`
- `fcvt.d.wu`
- `fclass.d`
- `fmin.d`
- `fmax.d`

## Files

- `riscv_adapter.py`
  - shared FP64 decode helpers
  - exact RISC-V oracles for all supported operations
  - canonical-NaN adaptation for `testfloat_gen` outputs
- `gen_directed_riscv.py`
  - emits a directed boundary suite across all supported ops
  - also writes a readable manifest that explains every case
- `gen_random_riscv.py`
  - emits a mixed random regression suite across all supported ops
  - long arithmetic ops use `testfloat_gen` as the random input source
  - expected results always come from the local RISC-V oracle
  - optional `--cross-check-testfloat` compares local oracle results against
    canonicalized `testfloat_gen` outputs for long arithmetic ops
- `gen_directed_fadd.py`
  - the earlier `fadd.d`-only directed generator is kept as a focused example

## Verification Strategy

The flow is intentionally split into two layers:

- Directed boundary vectors
  - one stable suite per supported instruction family
  - targets NaNs, infinities, signed zero, subnormal boundaries, overflow,
    underflow, exact-zero sign rules, min/max NaN behavior, conversion range
    limits, and rounding-mode pivots
- Random regression
  - long arithmetic ops: `fadd.d`, `fsub.d`, `fmul.d`, `fdiv.d`
    - random operand pairs come from `testfloat_gen`
    - expected results come from the local exact RISC-V oracle
    - optional cross-check verifies the oracle against canonicalized
      `testfloat_gen` results
  - short-path ops and conversions
    - random operands are generated locally with a bias toward special values
      such as zeros, infinities, NaNs, min/max normals, and subnormals
    - expected results come from the local exact RISC-V oracle

## Generate The Directed Suite

```bash
python3 verify/gen_directed_riscv.py
```

This writes:

- `verify/riscv_directed_vectors.txt`
- `verify/riscv_directed_manifest.txt`

## Generate A Mixed Random Suite

```bash
python3 verify/gen_random_riscv.py \
  --include-directed \
  --count-per-rm 16 \
  --seed 1 \
  --cross-check-testfloat \
  --output fpu_test_suite.tmp
```

Notes:

- For RM-sensitive ops, `--count-per-rm` means **per rounding mode**.
- For RM-insensitive ops, `--count-per-rm` means **total random vectors** for
  that op.
- `--cross-check-testfloat` currently applies to the long arithmetic ops that
  use `testfloat_gen` as their input source.

## Run The RTL Regression

```bash
make run SIM_TIME=50000000
```

The testbench reads `fpu_test_suite.tmp` and writes the final summary to
`log.tmp`.

## Smoke Result Recorded In This Workspace

The current framework was smoke-tested with:

```bash
python3 verify/gen_random_riscv.py \
  --include-directed \
  --count-per-rm 4 \
  --seed 1 \
  --cross-check-testfloat \
  --output fpu_test_suite.tmp

make run SIM_TIME=50000000
```

Observed result:

- total vectors: `327`
- RTL mismatches: `0`
