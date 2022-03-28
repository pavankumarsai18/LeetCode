class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lo = 0
        hi = len(nums) - 1
        
        while hi >= lo:
            mid = lo + (hi - lo)//2
            
            if nums[mid] == target:
                return mid
            
            elif nums[mid] >= nums[lo]:
                if nums[mid] > target >= nums[lo]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            
            else:
                if nums[hi] >= target > nums[mid]:
                    lo = mid + 1
                else:
                    hi = mid - 1
                    
        return -1
                    
            
                    
