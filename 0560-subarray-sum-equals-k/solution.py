class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        curSum = 0
        prefixSum = {0:1}
        
        for num in nums:
            curSum += num
            target = curSum - k
            
            if target in prefixSum:
                result += prefixSum[target]
            if curSum not in prefixSum:
                prefixSum[curSum] = 0
            prefixSum[curSum] += 1
            
        return result
        
