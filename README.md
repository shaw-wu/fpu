# FPU 硬件设计
>参考Berkeley Hard Float设计

本项目是FPU硬件设计,目标是支持单/双精度运算，集成到riscv处理器核心，完整支持RV F/D的全部运算指令。

目前支持指令：

| operation  | sel  | operation  | sel  |
| ---------- | ---- | ---------- | ---- |
|   fadd.d   | 5'h00 | fsngjx.d   | 5'h09 |
|   fsub.d   | 5'h01 |   fcvt.w.d   | 5'h0a |
|   fmul.d   | 5'h02 |   fcvt.wu.d   | 5'h0b |
|   fdiv.d   | 5'h03 |   fcvt.d.w   | 5'h0c |
|   feq.d   | 5'h04 |   fcvt.d.wu   | 5'h0d |
|   flt.d   | 5'h05 |  fclass.d   | 5'h0e |
|   fle.d   | 5'h06 |   fmin.d   | 5'h0f |
|   fsgnj.d   | 5'h07 |   fmax.d   | 5'h10 |
|   fsgnjn.d   | 5'h08 |||

其中乘除法计算需要**3个周期**（还没切流水）、加减法计算需要**5个周期**、浮点转整数计算需要**2个周期**，其余计算均为**1个周期**。**除法运算使用模拟器**。

fpu顶层端口如下：

| port  | flow  | width  | function |
| ----- | ----- | ----- | ---|
|clk|input|1|clock|
|rst|input|1|reset(active high)| 
|i_valid|input|1|input valid|
|i_ready|output|1|input ready|
|sel|input|5| select operation|
|frm|input|3| round mode|
|fina|input|64|float data|
|finb|input|64|float data|
|ina|input|32|int data|
|o_valid|output|1|output valid|
|o_ready|input|1|output ready|
|fflags|output|5| float exception flags|
|fresult|output|64| result|

整数会在fresult端口低位输出。

当前fpu流水线不支持乱序执行，不同流水级数的运算有不一样的处理优先级，分为3个优先级，从高到低为priority0、priority1和priority2,其中乘除法、加减法为priority0,浮点转整数计算为priority1,其余为priority2.此实现方式表明本FPU流水线通常会存在空泡，但输出顺序是不变的。

## 后续工作
1.提供单精度浮点兼容;

2.乘法流水线切分;

3.优化时序与面积（包括但不限于：改动流水划分、模块复用、算法升级等）;

4.设计浮点除法硬件.
