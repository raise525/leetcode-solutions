int majorityElement(int* nums, int numsSize) {
    int x = 0, votes = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (votes == 0) x = num;
        votes += (num == x) ? 1 : -1;
    }
    return x;
}