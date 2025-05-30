class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n          = len(nums)
        if n <= 1:
            return 1
        prevDiff   = nums[1] - nums[0]
        count = 2 if prevDiff != 0 else 1

        for i in range(2,n):
            diff = nums[i] - nums[i-1]
            if diff > 0 and prevDiff <= 0 or diff < 0 and prevDiff >= 0:
                count += 1
                prevDiff = diff
        
        return count
            
            
        
        
        
        
        
        
        
