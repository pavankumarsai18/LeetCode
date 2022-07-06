class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        seen = {}
        maxLength = 0
        prefixSum = 0
        for i, num in enumerate(nums):
            prefixSum += num
            if prefixSum == k:
                maxLength = max(maxLength, i+1)
            
            if prefixSum - k in seen:
                maxLength = max(maxLength, i - seen[prefixSum-k])
            
            if prefixSum not in seen:
                seen[prefixSum] = i
        
        return maxLength
            
            
            
