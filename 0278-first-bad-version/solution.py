# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        lo = 1
        hi = n
        
        while hi >= lo:
            mid = (lo + hi)//2
            
            result = isBadVersion(mid)
            if not result:
                lo = mid + 1
            else:
                nextVal = isBadVersion(mid - 1)
                if nextVal == False:
                    return mid
                hi = mid - 1
        return n
                
                
                
