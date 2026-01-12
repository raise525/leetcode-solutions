from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        if not nums :
            return
        
        j = 0 #j指向当前非零元素应该放置的位置

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j] = nums[i]
                j+=1

        # 将剩余位置填充为0
        nums[j:]=[0]*(len(nums)-j)
