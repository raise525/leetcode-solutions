#include <stdbool.h>
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1) == 0) && (n & 0x55555555) > 0;
}

int isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
}

