#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    
    // 分配足够的空间
    int max_len = (i > j ? i : j) + 3;
    char* ans = (char*)malloc(max_len * sizeof(char));
    if (!ans) return NULL;
    
    int idx = 0;    // ans的写入位置
    int carry = 0;  // 进位
    
    // 逐位相加
    while (i >= 0 || j >= 0) {
        int sum = carry;
        
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        ans[idx++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    
    // 处理最后的进位
    if (carry) {
        ans[idx++] = '1';
    }
    
    ans[idx] = '\0';  //给C语言字符串添加结束符
    
    // 反转字符串
    for (int l = 0, r = idx - 1; l < r; l++, r--) {
        char tmp = ans[l];
        ans[l] = ans[r];
        ans[r] = tmp;
    }
    
    return ans;
}