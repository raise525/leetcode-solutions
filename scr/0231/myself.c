#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool isPowerOfTwo(int n){
    if  (n  <=  0)  return  false;
    while  (n  >  1)  {
        if  (n  %  2  !=  0)  {  // 如果不能被2整除
            return  false;
        }
        n = n / 2;  // 除以2继续判断
    }
    return true;
}

int main(void) {
    // 你的代码
    isPowerOfTwo(8);  // 应该返回 true
    isPowerOfTwo(6);  // 应该返回 false
    printf("%d\n", isPowerOfTwo(8));  // 输出 1 (true)
    printf("%d\n", isPowerOfTwo(6));  // 输出 0 (
    return 0;
}