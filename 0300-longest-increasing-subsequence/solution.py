class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        dp = []
        
        for i in range(len(nums)):
            idx = bisect_left(dp, nums[i])
            
            if idx == len(dp):
                dp.append(nums[i])
            else:
                dp[idx] = nums[i]
        
        return len(dp)
