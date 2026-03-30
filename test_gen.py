import subprocess
import random
import os

# --- 配置区 ---
OUTPUT_FILE = "fpu_test_suite.tmp"
CASES_PER_MODE = 500  # 每种指令在每种舍入模式下生成的数量

# 指令配置表: { "指令名": [sel值, "testfloat函数名", 操作数个数] }
# sel 值你可以根据自己的译码逻辑修改
tasks = {
    "fadd.d":     [0x00, "f64_add", 2],
    "fsub.d":     [0x01, "f64_sub", 2],
    "fmul.d":     [0x02, "f64_mul", 2],
    "fdiv.d":     [0x03, "f64_div", 2],
    "feq.d":      [0x04, "f64_eq_quiet",  2],
    "flt.d":      [0x05, "f64_lt_quiet",  2],
    "fle.d":      [0x06, "f64_le_quiet",  2], # 比较指令通常不收 frm 影响，但为了统一格式也遍历一次
    "fcvt.w.d":   [0x0a, "f64_to_i32", 1],
    "fcvt.wu.d":  [0x0b, "f64_to_ui32",1],
    "fcvt.d.w":   [0x0c, "i32_to_f64", 1],
    "fcvt.d.wu":  [0x0d, "ui32_to_f64",1],
    "fmin.d":     [0x0f, "f64_min", 2],
    "fmax.d":     [0x10, "f64_max", 2],
}

# RISC-V 舍入模式映射
rm_modes = {
    0: "-rnear_even",   # RNE
    1: "-rminMag",      # RTZ
    2: "-rmin",         # RDN
    3: "-rmax",         # RUP
    4: "-rnear_maxMag"  # RMM
}

def run_gen():
    all_cases = []
    
    for name, config in tasks.items():
        sel, func, op_num = config
        
        # 遍历 5 种舍入模式
        for frm_val, rm_flag in rm_modes.items():
            print(f"Generating {name} (RM:{frm_val})...")
            
            # 比较指令和整数转浮点在 TestFloat 中可能不接受某些 RM 参数
            # 这里简单处理：如果报错则尝试不带 RM 参数运行
            #cmd = ["./testfloat_gen", func, rm_flag, "-n", str(CASES_PER_MODE)]
            cmd = ["./testfloat_gen", func, rm_flag]
            
            try:
                result = subprocess.run(cmd, capture_output=True, text=True)
                if result.returncode != 0:
                    # 某些指令可能不支持所有 RM，尝试默认运行
                    cmd = ["./testfloat_gen", func]
                    result = subprocess.run(cmd, capture_output=True, text=True)
                
                lines = result.stdout.strip().split('\n')
                for line in lines:
                    parts = line.split()
                    if not parts: continue
                    
                    # 统一格式化为: opa opb res fflags frm sel
                    if op_num == 2:
                        # 格式: opa opb res flags
                        opa, opb, res, flags = parts[0], parts[1], parts[2], parts[3]
                    else:
                        # 格式: opa res flags (单操作数)
                        opa, opb, res, flags = parts[0], "00000000", parts[1], parts[2]
                    
                    # 组合成一行数据
                    case_str = f"{opa} {opb} {res} {flags} {frm_val:02x} {sel:02x}"
                    all_cases.append(case_str)
                    
            except Exception as e:
                print(f"Error generating {name}: {e}")

    # 打乱所有测试样例的顺序
    print("Shuffling cases...")
    random.shuffle(all_cases)

    # 写入文件
    with open(OUTPUT_FILE, "w") as f:
        for c in all_cases:
            f.write(c + "\n")
            
    print(f"\n成功！生成了 {len(all_cases)} 条测试样例。")
    print(f"输出文件: {OUTPUT_FILE}")

if __name__ == "__main__":
    run_gen()
