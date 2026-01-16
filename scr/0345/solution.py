
class Solution:
    def reverseVowels(self, s: str) -> str:
        l, r = 0, len(s) - 1
        chars = list(s)
        vowel = set('aeiouAEIOU')

        while l < r:
            # 找到左边的元音
            while l < r and chars[l] not in vowel:
                l += 1
            # 找到右边的元音
            while l < r and chars[r] not in vowel:
                r -= 1
            
            # 交换
            chars[l], chars[r] = chars[r], chars[l]
            l += 1
            r -= 1

        return ''.join(chars)

        