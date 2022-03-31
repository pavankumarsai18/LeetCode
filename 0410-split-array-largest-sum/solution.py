class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        
        def canSplit(largest):
            numarray = 0
            curSum = 0
            
            for n in nums:
                curSum += n
                if curSum > largest:
                    curSum = n
                    numarray += 1
            return (numarray + 1) <= m
            
        
        lo, hi = max(nums), sum(nums)
        res = hi
        while hi >= lo:
            mid = lo + (hi-lo)//2
            
            if canSplit(mid):
                res = mid
                hi = mid - 1
            else:
                lo = mid + 1
                
        return res
