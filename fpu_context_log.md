# FPU 项目上下文日志

日期：2026-04-11

## 项目概况

- 项目路径：`/home/shaw/fpu`
- 项目目标：面向 RISC-V RV F/D 的 FPU 硬件设计，参考 Berkeley HardFloat 思路。
- 当前重点：双精度 `.d` 指令支持。
- 顶层模块：`vsrc/fpu.v`
- 顶层接口：
  - 输入握手：`i_valid` / `i_ready`
  - 输出握手：`o_valid` / `o_ready`
  - 浮点输入：`fina` / `finb`，当前为 64 位
  - 整数输入：`ina`，当前为 32 位
  - 输出：`fresult` / `fflags`

## 当前实现理解

- 当前 FPU 流水线不支持乱序执行。
- 顶层通过 `priority0` / `priority1` / `priority2` 和事务计数器保持输出顺序。
- `priority0`：加减、乘法、除法。
- `priority1`：浮点转整数。
- `priority2`：比较、符号注入、分类、最值、整数转浮点等短路径操作。
- 加减法约 7 周期。
- 乘法约 9 周期。
- 浮点转整数约 2 周期。
- 除法目前通过 DPI-C/C 模拟器实现，不是纯硬件除法。
- `fadd` / `fmul` 已经是硬件流水。
- 内部使用类似 HardFloat 的 recoded 格式：
  - `torecFN`：IEEE-754 标准格式转内部 recoded 表示。
  - `tostdFN`：内部 recoded 表示转 IEEE-754 标准格式。
- 舍入支持：
  - `RNE`
  - `RTZ`
  - `RDN`
  - `RUP`
  - `RMM`

## 已确认结论

- 当前的 `fcvt.d.w` / `fcvt.d.wu` 是 32 位整数转双精度浮点。
- 32 位整数转 `float64` 总是精确可表示。
- 因此当前场景下：
  - 不需要真正做舍入。
  - `frm` 对结果不起作用。
  - `NX=0` 是合理的。
- 所以 `vsrc/cvt_wf.v` 里当前把 `nx` 固定为 `0`，对 `fcvt.d.w` / `fcvt.d.wu` 是可以接受的。

## 单精度支持讨论结论

推荐路线：保留当前 64 位顶层接口，新增 `.s` 指令译码和一套单精度参数化通路。

不建议一开始就做完全动态位宽的统一 FPU datapath，因为当前代码中仍有不少双精度写死常量。

### 推荐设计

- 顶层 `fina` / `finb` / `fresult` 继续保持 64 位。
- `.d` 指令继续走现有双精度通路。
- `.s` 指令新增单精度通路。
- 单精度输入/输出使用低 32 位。
- 如果未来接 RV64 浮点寄存器文件，建议按 RISC-V NaN-boxing 处理 `.s` 结果：
  - 高 32 位填 `1`
  - 低 32 位为单精度结果

### 单精度参数

- `FP_BITS = 32`
- `EXP_BITS = 8`
- `FRA_BITS = 23`
- `SIG_BITS = 24`
- `RECEXP_BITS = 9`
- `FDATA_SIZE = 5`
- `SIG_SIZE = 5`

### 需要重点修改的方向

- 参数化 `tostdFN` 中写死的 double 常量。
- 参数化 `fadd_round` / `fmul_round` 中写死的 double 指数边界。
- 参数化 `fadd` / `fmul` 中的 `QNaN` / `Inf` / 指数边界常量。
- 参数化或扩展 `cvt_wf`，因为 `fcvt.s.w` / `fcvt.s.wu` 需要舍入。
- 顶层新增 `.s` 指令译码。
- 顶层新增 `.s` 的结果打包、异常标志和 NaN-boxing 逻辑。
- 顶层比较、符号注入、分类、最值逻辑需要按 32 位重新切片，不能直接复用当前 64 位逻辑。

### 推荐开发顺序

1. 先支持短路径单精度指令：
   - `fsgnj.s`
   - `fsgnjn.s`
   - `fsgnjx.s`
   - `feq.s`
   - `flt.s`
   - `fle.s`
   - `fclass.s`
   - `fmin.s`
   - `fmax.s`
2. 再支持转换指令：
   - `fcvt.s.w`
   - `fcvt.s.wu`
   - `fcvt.w.s`
   - `fcvt.wu.s`
3. 再支持算术长路径：
   - `fadd.s`
   - `fsub.s`
4. 再支持：
   - `fmul.s`
5. 最后处理：
   - `fdiv.s`

## 下次续聊提示词

如果下次不是通过 `codex resume --last` 续接，而是新开会话，可以直接贴下面这段：

```text
继续 /home/shaw/fpu：RISC-V FPU，当前双精度为主，fpu.v 顶层，fadd/fmul 硬件流水，fdiv DPI-C，recoded 格式，保序优先级流水。我们之前聊到：32 位整数转双精度不需要舍入；下一步要设计单精度支持，建议保留 64 位顶层，新增 .s 译码和单精度参数化通路，并处理 NaN-boxing、pack/unpack、round 常量、比较/转换路径。
```

推荐续接命令：

```bash
codex resume --last
```
