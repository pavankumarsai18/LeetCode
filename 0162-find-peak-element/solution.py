class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n  = len(nums)
        lo = 0
        hi = n - 1
        
        while lo < hi:
            mid = lo + (hi - lo)//2
            
            if nums[mid] > nums[mid+1]:
                hi = mid
            else:
                lo = mid + 1
                
        return lo
