
#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    if(nums == NULL) return;

    int j = 0;
    for(int i = 0;i <numsSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }

    for(j;j < numsSize; j++){
        nums[j] =0;
    }
}