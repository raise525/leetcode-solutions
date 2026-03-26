#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    if(nums == NULL)  return 0;
    //if(val == NULL)   return numsSize;
    
    int j = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j ;
}