#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n <= 0) return "";
    
    // 初始字符串 "1"
    char* prev = (char*)malloc(2 * sizeof(char));
    prev[0] = '1';
    prev[1] = '\0';
    
    for (int i = 2; i <= n; i++) {
        int len = strlen(prev);
        // 分配足够大的空间，最坏情况下长度会翻倍
        char* curr = (char*)malloc((2 * len + 1) * sizeof(char));
        int currIndex = 0;
        int start = 0;
        int pos = 0;
        
        while (pos < len) {
            // 统计相同字符的个数
            while (pos < len && prev[pos] == prev[start]) {
                pos++;
            }
            // 将计数和字符添加到curr字符串
            int count = pos - start;
            // 处理计数可能超过9的情况，但题目中n≤30，count不会超过3,这里是为了将数字转换为字符串形式，所以要+ '0',特别的超过10的,个位和十位要分别处理！！！
            if (count >= 10) {
                curr[currIndex++] = count / 10 + '0';
                curr[currIndex++] = count % 10 + '0';
            } else {
                curr[currIndex++] = count + '0';  
            }
            curr[currIndex++] = prev[start];
            start = pos;
        }
        curr[currIndex] = '\0';
        
        // 释放prev并更新为curr
        free(prev);
        prev = curr;
    }
    
    return prev;
}