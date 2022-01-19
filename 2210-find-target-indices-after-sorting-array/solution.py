class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        nums.sort()
        
        hi = len(nums)-1
        lo = 0
        
        index = -1
        
        while hi >= lo:
            mid = (hi + lo)//2
            
            if nums[mid] == target:
                index = mid
                break
            elif nums[mid] < target:
                lo = mid+1
            else:
                hi = mid - 1
            
        
        if index == -1:
            return []
        
        
        result = []
        loIndex = hiIndex = index
        if index != -1:
            while loIndex >= 1 and nums[loIndex-1] == target:
                loIndex -= 1
            
            while hiIndex + 1 < len(nums) and nums[hiIndex + 1] == target:
                hiIndex += 1
        
        result = [i for i in range(loIndex, hiIndex+1)]
        return result
