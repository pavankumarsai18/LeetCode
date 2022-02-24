class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        
        result = [0 for _ in xrange(len(nums) + 1)]
        result[1] = nums[0]
        
        for i in xrange(2, len(nums)+1):
            result[i] = max(nums[i-1] + result[i-2], result[i-1])
        
        return max(result[-1], result[-2])
