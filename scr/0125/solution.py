class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 1. 过滤：只保留字母和数字
        # filter(str.isalnum, s) 会过滤掉所有非字母数字的字符
        filtered_chars = filter(str.isalnum, s)
        
        # 2. 连接：将过滤后的字符连接成字符串
        # ''.join() 将字符列表或迭代器连接成一个字符串
        cleaned_str = ''.join(filtered_chars)
        
        # 3. 转小写：将所有字符转换为小写（统一大小写）
        lower_str = cleaned_str.lower()
        
        # 4. 反转：将字符串反转
        reversed_str = lower_str[::-1]  # [::-1] 是Python切片技巧，表示反转
        
        # 5. 比较：判断原字符串和反转后的字符串是否相同
        return lower_str == reversed_str