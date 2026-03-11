int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    int nextGreater[10001];
    for(int i = 0; i <10001; i++){
        nextGreater[i] = -1;
    }

    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;

    for(int i = 0; i <nums2Size; i++){
        while(top >= 0 && nums2[i] > nums2[stack[top]]){
            nextGreater[nums2[stack[top]]] = nums2[i];
            top--;
        }
        stack[++top] = i;
    }

    for(int i = 0; i < nums1Size; i++){
        result[i] = nextGreater[nums1[i]];
    }

    free(stack);
    return result;
}