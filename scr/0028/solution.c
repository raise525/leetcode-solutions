int strStr(char* ss, char* pp) {
    int n = strlen(ss);  // 原串长度
    int m = strlen(pp);  // 匹配串长度
    
    // 如果匹配串为空，根据题意返回0
    if (m == 0) return 0;
    
    // 枚举原串的「发起点」
    // 注意：只需要枚举到 n - m 即可，因为再往后长度不够匹配
    for (int i = 0; i <= n - m; i++) {
        // 从原串的「发起点」和匹配串的「首位」开始，尝试匹配
        int a = i;  // 原串的当前比较位置
        int b = 0;  // 匹配串的当前比较位置
        
        // 逐个字符比较
        while (b < m && ss[a] == pp[b]) {
            a++;
            b++;
        }
        
        // 如果能够完全匹配（b走到了匹配串末尾）
        if (b == m) {
            return i;  // 返回原串的「发起点」下标
        }
    }
    
    return -1;  // 没找到，返回-1
}