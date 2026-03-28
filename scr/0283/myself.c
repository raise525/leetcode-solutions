#include "stdio.h"
void moveZeroes(int* nums, int numsSize){
    if(nums == NULL)  return ;
    int j = 0, i = 0;
    while(i < numsSize)
    {
        if(nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }

    while(j < numsSize)
    {
        nums[j] = 0;
        j++;
    }
}

int main() {
    // 就测这一个最典型的就够了
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    // sizeof(nums)：整个数组占用的总字节数
    // sizeof(nums[0])：数组中一个元素占用的字节数

    moveZeroes(nums, size);
    
    // 看一眼结果对不对
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    // 期望输出：1 3 12 0 0
    
    return 0;
}