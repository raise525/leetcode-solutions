class solution:
    def bitSquareSum(self,n:int)->int:
        """"计算每位数字的平方和"""
        total=0
        while n > 0:
            digit = n %10
            total += digit*digit
            n//=10
        return total
    def isHappy(self, n: int)->bool:
        """判读是否为快乐数（使用快慢指针法）"""
        slow = fast = n

        while True:
            slow = self.bitSquareSum(slow)
            fast = self.bitSquareSum(fast)
            fast = self.bitSquareSum(fast)

            if slow == fast:
                break

        return slow == 1