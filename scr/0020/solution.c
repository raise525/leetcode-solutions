#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;   //这里是先将top加1再赋值，遇到左括号时将其压入栈中
        } else {
            if (top == -1) return false;  //如果遇到右括号时栈为空，说明没有匹配的左括号，直接返回false

            char topChar = stack[top--];  //这里是先将top指向的字符保存到topChar中，然后再将top减1，弹出栈顶元素
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}