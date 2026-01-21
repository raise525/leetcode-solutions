#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        // n & 1 是取最低位， << (31 - i)是将最低位放到他反转后的位置，比如第一个要放到rev的第31位，|= 这个是表示rev和结果相或，1|0=1
        n >>= 1;
        //n右移以便找下一位
    }
    return rev;
}


int main() {
    // 测试用例
    uint32_t test_cases[] = {43261596, 964176192, 1, 0};
    int count = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < count; i++) {
        uint32_t original = test_cases[i];
        uint32_t reversed = reverseBits(original);
        printf("测试用例 %d:\n", i + 1);
        printf("  输入: %" PRIu32 "\n", original);
        printf("  输出: %" PRIu32 "\n\n", reversed);
    }
    
    return 0;
}