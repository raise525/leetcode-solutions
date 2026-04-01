#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int carry = 1;

    for(int i = digitsSize - 1; i >= 0; i-- )
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum /10;
        if(carry == 0)
        break;
    }

    if(carry == 0)
    {
        *returnSize = digitsSize;
        return digits;
    }
    else
    {
        //第一位为1，后面直接补零
        int* result = (int*)malloc(sizeof(int)*(digitsSize + 1));
        result[0] = 1;
        for(int i = 1; i <= digitsSize; i++){
            result[i] = 0;
        }

        *returnSize =digitsSize + 1;
        return result;
    }
}