class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n           = len(nums)
        return (n*n + n)/2 - sum(nums)
        
        
        
