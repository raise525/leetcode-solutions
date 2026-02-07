#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0){
        return 0;
    }

    int p = 0, q = 1;
    while(q < numsSize){
        if(nums[p] != nums[q]){
            nums[p + 1] = nums[q];
            p++;
        }
        q++;
    }
    return p+1;
}