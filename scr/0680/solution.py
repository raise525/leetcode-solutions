class Solution:
    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]

    def validPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                # 删除 s[i] 或者 s[j]
                return self.isPalindrome(s[i + 1: j + 1]) or self.isPalindrome(s[i: j])
            i += 1
            j -= 1
        return True  # s 本身就是回文串

