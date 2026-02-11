#include <stdbool.h>

bool idPowerOfTwo(int n){
    return n > 0 && (n & (n-1)) == 0;
}


/// @brief 循环除以二
/// @param n 
/// @return 
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    
    while (n > 1) {
        if (n % 2 != 0) {  // 如果不能被2整除
            return false;
        }
        n = n / 2;  // 除以2继续判断
    }
    return true;  // 最后剩下1，说明是2的幂
}