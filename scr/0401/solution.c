char** readBinaryWatch(int turnedOn, int* returnSize) {
    // 分配最大可能的结果空间：12小时 * 60分钟 = 720种可能
    char** ans = malloc(sizeof(char*) * 12 * 60);
    *returnSize = 0;  // 初始化返回数组的大小为0
    
    // 遍历所有可能的时间
    for (int h = 0; h < 12; ++h) {      // 小时：0-11
        for (int m = 0; m < 60; ++m) {  // 分钟：0-59
            
            // 关键判断：当前时间亮着的LED数量是否等于turnedOn
            // __builtin_popcount(h) 计算小时数二进制表示中1的个数
            // __builtin_popcount(m) 计算分钟数二进制表示中1的个数
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                
                // 分配存储时间字符串的内存（"h:mm"格式最多需要6字节）
                char* tmp = malloc(sizeof(char) * 6);
                
                // 格式化时间，分钟始终显示两位（如 3:05 而不是 3:5）
                sprintf(tmp, "%d:%02d", h, m);
                
                // 将结果存入数组，并增加返回大小
                ans[(*returnSize)++] = tmp;
            }
        }
    }
    return ans;  // 返回结果数组
}


//char** 是指向字符指针的指针，然后这里的字符指针是时间tmp