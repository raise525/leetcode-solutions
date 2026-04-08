int hammingDistance(int x, int y){
    int count = 0;
    int xor = x ^ y; // XOR to find differing bits
    for(int i = 0; i < 32; i++){
        count += xor & (1 << i);
    }
    return count;
}