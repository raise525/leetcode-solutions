#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int hash[10001] = {0};// 哈希表，用于存储nums2中每个元素的下一个更大元素
    for(int i = 0; i < 10001; i++)
    {
        hash[i] = -1;// 初始化哈希表，默认值为-1，表示没有下一个更大元素
    }

    int* stack = (int*)malloc(nums2Size * sizeof(int));// 栈，用于存储nums2中的元素
    int top = -1;

    for(int i = 0; i <nums2Size; i++)
    {
        int current = nums2[i];
        while(top != -1 && stack[top] < current)
        {
            hash[stack[top]] = current;
            top--;// 弹出栈顶元素，更新哈希表中该元素的下一个更大元素
        }
        stack[++top] = current;
    }

    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    for(int i = 0; i < nums1Size; i++)
    {
        result[i] = hash[nums1[i]];// 根据哈希表，获取nums1中每个元素的下一个更大元素
    }
    free(stack);// 释放栈的内存
    return result;
}

void main()
{
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;
    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);// 输出结果
    }
    free(result);// 释放结果数组的内存
}