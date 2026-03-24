int removeDuplicates(int* nums, int numsSize)
{
    int i = 0; 
    int j = 1;
    while(j < numsSize)
    {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i + 1;
}