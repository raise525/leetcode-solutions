#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) 
        return "";
    
    // 分配内存并复制第一个字符串作为初始前缀
    char* ans = (char*)malloc(strlen(strs[0]) + 1);
    strcpy(ans, strs[0]);
    
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // 比较当前前缀和当前字符串
        while (j < strlen(ans) && j < strlen(strs[i])) {
            if (ans[j] != strs[i][j])
                break;
            j++;
        }
        
        // 截断前缀到共同部分
        ans[j] = '\0';
        
        // 如果前缀为空，提前返回
        if (j == 0) {
            return ans;
        }
    }
    
    return ans;
}

// 测试代码
int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    char* result1 = longestCommonPrefix(strs1, size1);
    printf("Test 1: %s\n", result1);  // 预期输出: "fl"
    free(result1);  // 记得释放内存
    
    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = 3;
    char* result2 = longestCommonPrefix(strs2, size2);
    printf("Test 2: %s\n", result2);  // 预期输出: ""
    free(result2);
    
    char* strs3[] = {"single"};
    int size3 = 1;
    char* result3 = longestCommonPrefix(strs3, size3);
    printf("Test 3: %s\n", result3);  // 预期输出: "single"
    free(result3);
    
    return 0;
}

