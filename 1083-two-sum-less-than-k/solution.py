class Solution(object):
    def twoSumLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        nums.sort()        
        l,r = 0, len(nums) - 1
        maxVal = -1
        
        while l < r:
            if nums[l] + nums[r] < k:
                maxVal = max(maxVal, nums[l] + nums[r])
                l += 1
            else:
                r -= 1
        
        
        return maxVal
