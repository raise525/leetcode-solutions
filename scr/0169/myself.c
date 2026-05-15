#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int ans = 0;
    int votes = 0;
    for (int i = 0; i < numsSize; i++) {
        if (votes == 0) {
            ans = nums[i];
        }
        votes += (nums[i] == ans) ? 1 : -1;
    }
    return ans;
}

void main()
{
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("The majority element is: %d\n", result);
}