#include <stdio.h>

int getSum(int a, int b){
    int carry = 0;
    while (b != 0) {
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main() {
    int a = 5;
    int b = 3;
    int result = getSum(a, b);
    printf("The sum of %d and %d is: %d\n", a, b, result);
    return 0;
}