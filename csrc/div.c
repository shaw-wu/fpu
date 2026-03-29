#include <stdint.h>
#include <math.h>
#include <fenv.h>
#include <stdio.h>

#define LATENCY 20  // 延迟周期数

typedef struct {
    unsigned char valid;
    double         value;
    unsigned char tuser; // {uf, of, nv}
} pipe_stage_t;

static pipe_stage_t pipe[LATENCY];  // 模拟流水线寄存器

extern "C" void fdiv_d(
    unsigned char  aclk,
    unsigned char  a_valid,
    unsigned char *a_ready,
    uint64_t      a_data,
    unsigned char  b_valid,
    unsigned char *b_ready,
    uint64_t      b_data,
    unsigned char *result_valid,
    unsigned char  result_ready,
    uint64_t     *result_data,
    unsigned char *result_tuser  // {uf, of, nv}
) {
    // 假设 ready 恒为 1（流水线能随时接收数据）
    *a_ready = 1;
    *b_ready = 1;

    // 时钟上升沿推进流水线
    if (aclk) {
        // 最后一级输出
        *result_valid = pipe[LATENCY-1].valid;
        if (*result_valid) {
            union { uint64_t u; double f; } ur;
            ur.f = pipe[LATENCY-1].value;
            *result_data  = ur.u;
            *result_tuser = pipe[LATENCY-1].tuser;
        } else {
            *result_data  = 0;
            *result_tuser = 0;
        }

        // 向后移动流水线
        for (int i = LATENCY-1; i > 0; i--) {
            pipe[i] = pipe[i-1];
        }

        // 第一阶段：接收输入并计算
        if (a_valid && b_valid) {
            feclearexcept(FE_ALL_EXCEPT);

            union { uint64_t u; double f; } ua, ub;
            ua.u = (uint64_t)(a_data & 0xFFFFFFFFFFFFFFFF);
            ub.u = (uint64_t)(b_data & 0xFFFFFFFFFFFFFFFF);

            double r = ua.f / ub.f;
						int flags = fetestexcept(FE_ALL_EXCEPT);

            volatile uint8_t nv = (flags & FE_INVALID)   ? 1 : 0;
            volatile uint8_t of = (flags & FE_OVERFLOW)  ? 1 : 0;
            volatile uint8_t uf = (flags & FE_UNDERFLOW) ? 1 : 0;
			volatile uint8_t dz = (flags & FE_DIVBYZERO) ? 1 : 0;
						//printf("nv:%x of:%x uf:%x flags:%x\n",nv , of, uf, flags);

            pipe[0].valid = 1;
            pipe[0].value = r;
            pipe[0].tuser = (dz << 3) | (uf << 0) | (of << 1) | (nv << 2);
        } else {
            pipe[0].valid = 0;
        }
    }
}
