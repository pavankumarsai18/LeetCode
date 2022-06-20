class Solution:   
    def canPartition(self, nums: List[int]) -> bool:
        total    = sum(nums)
        
        if total%2 == 1:
            return False
        
        dp = [False]*(total//2 + 1)
        dp[0] = True
        
        for num in nums:
            for subsetSum in range(total//2,num-1,-1):
                dp[subsetSum] = dp[subsetSum] or dp[subsetSum-num]
        return dp[total//2]
            
        
