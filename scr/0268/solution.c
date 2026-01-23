int missingNumber(int* nums, int numsSize) {
    int xor = 0;
    
    // 异或所有数组元素
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }
    
    // 异或完整序列 0...n
    for (int i = 0; i <= numsSize; i++) {
        xor ^= i;
    }
    
    return xor;
}