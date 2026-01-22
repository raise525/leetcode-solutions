#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int hammingWeight(uint32_t n){
    int count = 0;
    while(n){
        count += (n & 1);  // 如果最后一位是1，count加1；如果是0，加0
        n >>= 1;
    }
    return count;
}

int hammingWeight(uint32_t n){
    int ret = 0;
    while(n){
        n &= n-1;
        ret++;
    }
    return ret;
}