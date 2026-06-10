# RISC-V 验证说明

这个目录保存了当前工程的 **RISC-V 语义验证框架**，覆盖仓库里目前已经支持的全部
FP64（`.d`）运算，不再只针对 `fadd.d`。

## 覆盖范围

当前验证框架覆盖以下指令：

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

## 目录内文件说明

- `riscv_adapter.py`
  - 提供 FP64 的位级解码、分类、舍入和异常标志辅助函数
  - 提供当前所有已支持运算的 RISC-V 精确 oracle
  - 提供 `testfloat_gen` 输出到 RISC-V 语义的适配逻辑，例如 canonical NaN 规约
- `gen_directed_riscv.py`
  - 生成“定向边界测试集”
  - 输出一份向量文件，以及一份可读性更强的 manifest，说明每条边界样例的目的
- `gen_random_riscv.py`
  - 生成“混合随机回归测试集”
  - 长路径算术类用 `testfloat_gen` 提供随机输入分布
  - 所有期望结果统一由本地 RISC-V oracle 给出
  - 可选 `--cross-check-testfloat`，用于把本地 oracle 和经过语义适配后的 `testfloat_gen` 结果再对拍一遍
- `gen_directed_fadd.py`
  - 保留的 `fadd.d` 专项定向样例生成器
  - 适合单独研究 `fadd.d` 的边界案例，不作为总入口

## 验证思路

当前验证流程分成两层。

### 1. 定向边界验证

目的不是追求样本数量，而是确保规格里的关键分支都被显式打到。当前覆盖重点包括：

- `qNaN` / `sNaN`
- `+inf` / `-inf`
- `+0` / `-0`
- normal / subnormal 边界
- overflow / underflow
- 精确为 0 时的符号规则
- `fmin.d` / `fmax.d` 的 NaN 与 `±0` 行为
- 浮点转整数的范围边界与舍入边界
- 多种舍入模式下的 tie / near-tie 情况

### 2. 随机回归验证

随机回归不是简单均匀撒点，而是按运算类别区分：

- 长路径算术：`fadd.d`、`fsub.d`、`fmul.d`、`fdiv.d`
  - 随机输入来自 `testfloat_gen`
  - 期望结果来自本地 RISC-V oracle
  - 可以再用 `--cross-check-testfloat` 与语义适配后的 `testfloat_gen` 结果做交叉校验
- 短路径与转换类
  - 随机输入由本地脚本生成
  - 输入会偏向特殊值，例如 `0`、`inf`、`NaN`、最小/最大 normal、subnormal、整数边界值
  - 期望结果全部来自本地 RISC-V oracle

## 重要注意事项

- `flt.d` 和 `fle.d` 在 RISC-V 里对 **任意 NaN** 都要置 `NV`，因此如果直接使用
  `testfloat_gen` 做参考，必须使用 `f64_lt` / `f64_le`，不能使用 `*_quiet` 版本。
- `fcvt.w.d` 和 `fcvt.wu.d` 不能直接把 raw `testfloat_gen` 整数输出当成
  RISC-V golden，因为 invalid conversion 时两者的结果约定不同。
  这两类运算必须以本地 RISC-V oracle 作为权威期望值来源。

## 生成定向边界测试集

```bash
python3 verify/gen_directed_riscv.py
```

默认输出：

- `verify/riscv_directed_vectors.txt`
- `verify/riscv_directed_manifest.txt`

其中：

- `riscv_directed_vectors.txt` 是可直接喂给 testbench 的向量文件
- `riscv_directed_manifest.txt` 便于人工检查每条边界样例的意义

## 生成混合随机回归测试集

推荐命令：

```bash
python3 verify/gen_random_riscv.py \
  --include-directed \
  --count-per-rm 16 \
  --seed 1 \
  --cross-check-testfloat \
  --output fpu_test_suite.tmp
```

参数说明：

- `--include-directed`
  - 在随机回归前先把定向边界样例也并入测试集
- `--count-per-rm`
  - 对于受舍入模式影响的指令，表示“每种舍入模式的随机样本数”
  - 对于不受舍入模式影响的指令，表示“该指令总随机样本数”
- `--seed`
  - 控制随机种子，便于复现
- `--cross-check-testfloat`
  - 当前主要作用于长路径算术类，用于额外核对本地 oracle 是否与语义适配后的 `testfloat_gen` 结果一致

## 运行 RTL 回归

测试集生成后，直接运行：

```bash
make run SIM_TIME=50000000
```

当前 testbench 会：

- 从仓库根目录读取 `fpu_test_suite.tmp`
- 将不匹配项写入 `log.tmp`
- 在终端输出 `Total` 和 `Error`

## 当前工作区中已经完成的验证记录

在当前工作区里，这套框架已经完成了至少两轮有代表性的回归：

- 一轮 `327` 条混合样例回归，`RTL mismatch = 0`
- 一轮 `10659` 条更大规模的全运算混合回归，`RTL mismatch = 0`

如果你只是想快速复现当前推荐的验证流程，优先使用本目录下的脚本，不要再把
`test_gen.py` 当作唯一入口。`test_gen.py` 仍然能用于基础向量生成，但它不是当前最完整的
RISC-V 语义验证入口。
