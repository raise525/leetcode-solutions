void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1, j = n - 1, p = nums1Size - 1;
    
    // ❌ 错误1: 使用按位与运算符 & 而不是逻辑与 &&
    // 问题: i & j != 0 会先计算 j != 0，然后与 i 进行按位与运算
    // 导致循环条件完全错误，可能提前退出或死循环
    // 正确: while(i >= 0 && j >= 0)
    while( i & j != 0)
    {
        if(nums1[i] < nums2[j])
        {
            nums1[p] = nums2[j];
            j--;
        }
        else
        {
            nums1[p] = nums1[i];
            i--;
        }
        p--;
    }
    
    // ❌ 错误2: 边界条件判断错误
    // 问题: j > 0 会漏掉 j == 0 的情况，导致最后一个元素未被复制
    // 正确: if(j >= 0) 或者直接使用 while(j >= 0)
    if(j > 0)
    {
        // ❌ 错误3: for循环语法不规范
        // 问题: for(j; j > 0; j--) 中第一个表达式 j 无意义
        // 而且循环条件 j > 0 同样漏掉 j == 0 的情况
        // 正确: for(; j >= 0; j--) 或 while(j >= 0)
        for(j; j > 0; j--){
            nums1[p] = nums2[j];
            p--;
        }
    }
    
    // ❌ 错误4: 缺少对 i >= 0 情况的处理
    // 虽然 i 剩余的元素已经在正确位置，但理论上应该处理
    // 不过这不是必须的，因为剩余元素已经在 nums1 的前面部分
}