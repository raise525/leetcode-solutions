#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans ^= nums[i];
    }
    return ans;
}


//如果想用双重循环怎么写呢？我想用另一个数组的来统计出现的次数，但是你还很难规定那个数组的大小，不然就是浪费空间