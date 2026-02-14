char findTheDifference(char* s, char* t) {
    int n = strlen(s), m = strlen(t);
    int ret = 0;
    for (int i = 0; i < n; i++){
        ret ^= s[i];
    }
    for (int i = 0; i < m; i++){
        ret ^= t[i];
    }
    return ret;
}

char findTheDifference(char* s, char* t) {
    int hash[26] = {0};  // 哈希表，记录26个字母的出现次数
    
    // 遍历字符串s，记录每个字母出现的次数
    for (int i = 0; s[i] != '\0'; i++) {
        hash[s[i] - 'a']++;   //这里其实就是哈希映射了，数组是实现哈希表的一种方式
    }
    
    // 遍历字符串t，减去每个字母出现的次数
    for (int i = 0; t[i] != '\0'; i++) {
        hash[t[i] - 'a']--;
        
        // 如果某个字母的计数变为负数，说明这个字母就是被添加的
        if (hash[t[i] - 'a'] < 0) {
            return t[i];
        }
    }
    
    return ' ';  // 默认返回（实际上不会执行到这里）
}