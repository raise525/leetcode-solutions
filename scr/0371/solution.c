int getSum(int a, int b) {
    // 循环，当进位为 0 时跳出
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;  // 进位
        a ^= b;                                          // 无进位和
        b = carry;                                       // 进位作为下一轮的加数
    }
    return a;
}