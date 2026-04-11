# FPU 硬件设计

参考 Berkeley HardFloat 思路实现的 RISC-V 浮点单元（FPU）。

当前版本以 **双精度（`.d`）** 为主，目标是集成到 RISC-V 处理器核心中，逐步覆盖 RV F/D 所需的浮点计算、比较、转换与分类能力。工程内已经包含 Verilog 实现、Verilator 仿真入口，以及基于向量文件的测试框架。

## 项目特点

- 面向 RISC-V 浮点扩展的 FPU 顶层设计，当前重点支持双精度指令
- 采用类似 HardFloat 的 recoded 浮点表示，便于分类、规格化和舍入处理
- 使用保序流水线：即使不同操作延迟不同，输出顺序仍与输入顺序一致
- 已具备 Verilator + C++ 仿真环境，可配合波形与测试向量进行验证
- `fdiv.d` 当前通过 DPI-C/C 模拟器实现，尚未替换为纯硬件除法器

## 当前支持的双精度指令

| operation | sel | operation | sel |
| --- | --- | --- | --- |
| `fadd.d` | `5'h00` | `fsgnjx.d` | `5'h09` |
| `fsub.d` | `5'h01` | `fcvt.w.d` | `5'h0a` |
| `fmul.d` | `5'h02` | `fcvt.wu.d` | `5'h0b` |
| `fdiv.d` | `5'h03` | `fcvt.d.w` | `5'h0c` |
| `feq.d` | `5'h04` | `fcvt.d.wu` | `5'h0d` |
| `flt.d` | `5'h05` | `fclass.d` | `5'h0e` |
| `fle.d` | `5'h06` | `fmin.d` | `5'h0f` |
| `fsgnj.d` | `5'h07` | `fmax.d` | `5'h10` |
| `fsgnjn.d` | `5'h08` |  |  |

## 时延与流水线特性

当前实现不是乱序执行流水线，而是通过不同优先级的事务计数器维持 **输入顺序 = 输出顺序**。

### 指令时延

| 类型 | 周期数 | 说明 |
| --- | --- | --- |
| `fadd.d` / `fsub.d` | 7 | 硬件流水 |
| `fmul.d` | 9 | 硬件流水 |
| `fcvt.w.d` / `fcvt.wu.d` | 2 | 浮点转整数 |
| 其余短路径操作 | 1 | 比较、符号注入、分类、最值、整数转浮点等 |
| `fdiv.d` | 取决于模拟器 | 当前使用 DPI-C/C 模拟模型 |

### 优先级划分

- `priority0`：`fadd.d` / `fsub.d` / `fmul.d` / `fdiv.d`
- `priority1`：`fcvt.w.d` / `fcvt.wu.d`
- `priority2`：比较、符号注入、分类、最值、整数转浮点等短路径操作

这种设计实现简单、结果保序，但在混合不同延迟指令时会产生流水空泡。

## 顶层接口

顶层模块为 `vsrc/fpu.v`，接口定义如下：

| port | dir | width | 说明 |
| --- | --- | --- | --- |
| `clk` | input | 1 | 时钟 |
| `rst` | input | 1 | 高电平复位 |
| `i_valid` | input | 1 | 输入有效 |
| `i_ready` | output | 1 | 输入就绪 |
| `sel` | input | 5 | 操作选择 |
| `frm` | input | 3 | 舍入模式 |
| `fina` | input | 64 | 浮点输入 A |
| `finb` | input | 64 | 浮点输入 B |
| `ina` | input | 32 | 整数输入 |
| `o_valid` | output | 1 | 输出有效 |
| `o_ready` | input | 1 | 输出接受 |
| `fflags` | output | 5 | IEEE-754 异常标志 |
| `fresult` | output | 64 | 运算结果 |

补充说明：

- 整数转换结果放在 `fresult[31:0]`
- 当前顶层数据通路按双精度参数组织，`fina` / `finb` / `fresult` 均为 64 位
- `frm` 当前使用的舍入模式为 `RNE` / `RTZ` / `RDN` / `RUP` / `RMM`

## 工程结构

```text
.
├── csrc/                 # Verilator 仿真与 DPI-C 代码
│   ├── div.c             # fdiv 的 C 模型
│   └── sim_main.cpp      # 仿真主程序
├── vsrc/                 # Verilog 源码
│   ├── fpu.v             # FPU 顶层
│   ├── fadd*.v           # 加/减法相关模块
│   ├── fmul*.v           # 乘法相关模块
│   ├── fdiv.v            # 除法封装
│   ├── cvt_*.v           # 浮点/整数转换模块
│   ├── torecFN.v         # IEEE-754 -> recoded
│   ├── tostdFN.v         # recoded -> IEEE-754
│   ├── testbench.v       # Verilog 测试平台
│   └── mul/              # 乘法器子模块
├── Makefile              # 构建、运行、波形查看
└── fpu_test_suite.tmp    # 仿真输入向量（运行时读取）
```

## 构建与仿真

### 环境依赖

- `verilator`
- GNU `make`
- 支持 C++ 编译的工具链
- `gtkwave`（可选，仅用于查看波形）

### 常用命令

```bash
# 清理构建目录
make clean

# 编译并运行默认仿真
make run

# 启用波形并运行仿真
make run ENABLE_WAVEFORM=1

# 自定义仿真时长
make run SIM_TIME=1000000

# 打开波形
make wave
```

说明：

- 默认顶层为 `testbench`
- 默认仿真时间由 `SIM_TIME` 控制，缺省值为 `50000000`
- 启用 `ENABLE_WAVEFORM=1` 时，会生成 `build/dump.vcd`

## 测试向量格式

`vsrc/testbench.v` 会从仓库根目录读取 `fpu_test_suite.tmp`，每一行格式如下：

```text
fina finb expected_result expected_fflags frm sel
```

均按十六进制文本读取。

含义如下：

- `fina`：输入操作数 A
- `finb`：输入操作数 B
- `expected_result`：期望结果
- `expected_fflags`：期望异常标志
- `frm`：舍入模式
- `sel`：操作选择编码

仿真日志默认写入 `log.tmp`。

## 测试集使用

本项目当前使用根目录下的 `fpu_test_suite.tmp` 作为仿真输入测试集，`vsrc/testbench.v` 启动后会自动读取该文件并按行发射测试向量。

### 1. 生成测试集

仓库中提供了 `test_gen.py`，用于调用 `./testfloat_gen` 生成参考测试向量：

```bash
python3 test_gen.py
```

执行后会在仓库根目录生成或覆盖：

```text
fpu_test_suite.tmp
```

生成脚本位置与作用：

- `test_gen.py`：组织测试任务、舍入模式、输出格式并打乱顺序
- `testfloat_gen`：外部参考向量生成器，用于给出 golden result 和 `fflags`

### 2. 运行测试集

生成完成后，直接运行仿真即可：

```bash
make run
```

如果需要同时看波形：

```bash
make run ENABLE_WAVEFORM=1
make wave
```

### 3. 查看结果

仿真过程中：

- 终端会打印发送/接收进度与最终错误统计
- 不匹配项会写入根目录下的 `log.tmp`
- 启用波形时，波形文件输出到 `build/dump.vcd`

当全部向量执行完成后，终端会输出类似结果：

```text
TEST FINISH
Total  = ...
Error  = ...
```

其中 `Error = 0` 表示当前测试集全部通过。

### 4. 测试集字段约定

结合当前 `vsrc/testbench.v` 的接线方式，使用测试集时需要注意：

- 双操作数指令直接使用 `fina` 和 `finb`
- 单操作数指令通常只使用 `fina`，`finb` 可以填 `0`
- `fcvt.d.w` / `fcvt.d.wu` 这类整数转浮点测试，整数输入实际取自 `fina[31:0]`
- `fcvt.w.d` / `fcvt.wu.d` 的整数结果写在 `fresult[31:0]`

也就是说，当前测试集文件中虽然没有单独的 `ina` 列，但整数输入已经通过 `fina` 低 32 位传给 DUT。

### 5. 自定义测试范围

如果你想只测一部分指令或舍入模式，可以直接修改 `test_gen.py` 中的配置：

- `tasks`：控制参与生成的指令集合
- `rm_modes`：控制舍入模式
- `OUTPUT_FILE`：控制输出文件名

如果想控制每类测试的样本量，可以看 `test_gen.py` 里的 `CASES_PER_MODE`。目前脚本中传给 `testfloat_gen` 的 `-n` 参数是注释状态，因此实际生成数量取决于当前 `testfloat_gen` 的默认行为；如果你需要固定每种模式的样本量，可以恢复该参数并按需调整。

### 6. 常见问题

- `ERROR: file open failed`：通常是缺少根目录下的 `fpu_test_suite.tmp`
- `make wave` 提示没有 `dump.vcd`：需要先执行 `make run ENABLE_WAVEFORM=1`
- 测试集中混合长短延迟指令时，吞吐可能下降，但结果顺序应保持不变

## 当前限制

- 当前主要实现双精度 `.d` 指令，尚未完成单精度 `.s` 全面支持
- `fdiv.d` 仍依赖 DPI-C/C 模型，不是纯 RTL 硬件除法器
- 顶层流水线不支持乱序执行，混合长短路径操作时可能出现空泡
- 目前整数输入接口为 32 位，因此 `fcvt.d.w` / `fcvt.d.wu` 面向 32 位整数转换

## 后续工作

1. 增加单精度浮点兼容与 `.s` 指令支持
2. 继续细化乘法流水线切分
3. 优化时序与面积，包括流水划分、模块复用与算法升级
4. 设计纯硬件浮点除法单元
