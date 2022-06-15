class Solution:
    def check(self, nums: List[int]) -> bool:
        num_pivot = 0
        n = len(nums)
        index = 0
        first = nums[0]
        
        
        while index < n-1 and nums[index] >= first and nums[index] <= nums[index + 1]:
            index += 1
        index += 1
        # strictly increasing 
        if index == n:
            return True
        # One pivot non zero index
        while index < n-1 and nums[index] <= first and nums[index] <= nums[index + 1]:
            index += 1
            
        if index == n - 1 and nums[index] <= first:
            return True
        return False
