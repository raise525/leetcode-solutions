#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 原地操作
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] = digits[i] % 10;
        if (digits[i] != 0) {
            *returnSize = digitsSize;
            int* result = (int*)malloc(sizeof(int) * digitsSize);
            for (int j = 0; j < digitsSize; j++) {
                result[j] = digits[j];
            }
            return result;
        }
    }
    
    // 需要增加一位的情况（如 999 -> 1000）
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = 0;
    }
    return result;
}