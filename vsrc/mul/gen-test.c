#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define TEST_COUNT 100000  // 测试样例数量

int main() {
    FILE *fp = fopen("mul_test_data.tmp", "w");
    if (!fp) return 1;

    srand(time(NULL));

    for (int i = 0; i < TEST_COUNT; i++) {
        // 随机生成两个 32 位整数
        int32_t a = (int32_t)((uint32_t)rand() | ((uint32_t)rand() << 16));
        int32_t b = (int32_t)((uint32_t)rand() | ((uint32_t)rand() << 16));
        
        // 计算 64 位结果 (金标准)
        int64_t res_u = (int64_t)a * (int64_t)b;
        
        // 写入文件格式：a b res_u
        fprintf(fp, "%08x %08x %016llx\n", a, b, res_u);
    }

    fclose(fp);
    printf("Successfully generated %d test cases in mul_test_data.txt\n", TEST_COUNT);
    return 0;
}
