class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        # [0 ...r r + 1 ... n]
        # 0 .. r it is a increasing sequence /subarray
        # r+1 .. n it is a increasing sequence/subarray but every element in the seond half is less than the first hals
        
        n = len(nums)
        lo, hi = 0, n-1
        minIndex = 0
        while lo < hi:
            mid = lo + (hi-lo)//2
            minIndex = mid + 1
            
            before = nums[mid-1] if mid-1 >= 0 else float('-inf')
            after  = nums[mid+1] if mid+1 < n  else float('-inf')
            
            if before < nums[mid] > after:
                break
            elif before > nums[mid] < after:
                minIndex = mid
                break
            elif nums[mid] >= nums[0]:
                lo = mid+1
            else:
                hi = mid-1
            
        return min(nums[0], nums[minIndex])
                
