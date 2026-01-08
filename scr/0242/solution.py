class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 技巧1: 先判断长度
        if len(s) != len(t):
            return False
        
        # 技巧2: 初始化26个字母的计数数组
        count = [0] * 26
        
        # 技巧3: 遍历s，对应位置+1
        for char in s:
            index = ord(char) - ord('a')
            count[index] += 1
        
        # 技巧4: 遍历t，对应位置-1
        for char in t:
            index = ord(char) - ord('a')
            count[index] -= 1
        
        # 技巧5: 检查是否全为零
        for num in count:
            if num != 0:
                return False
        return True