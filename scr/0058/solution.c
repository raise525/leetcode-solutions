#include <stdio.h>

int lengthOfLastWord(char * s) {
    // 边界检查
    if (s == NULL || *s == '\0') return 0;

    char *p = s;
    // 1. 先移动到字符串末尾
    while (*p != '\0') {
        p++;
    }
    p--; // 指向最后一个字符

    // 2. 从后往前跳过末尾的空格
    while (p >= s && *p == ' ') {
        p--;
    }

    // 3. 从最后一个字母开始计数
    int wordLength = 0;
    while (p >= s && *p != ' ') {
        wordLength++;
        p--;
    }

    return wordLength;
}