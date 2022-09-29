class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        n      = len(arr)
        lo, hi = 0, n-1
        index  = 0
        
        
        while lo < hi:
            mid = (lo + hi)//2
            if arr[mid] >= x:
                hi = mid
            else:
                lo = mid + 1
                
        index = lo
            
        lessThan    = []
        greaterThan = []
        
        left, right = lo - 1, lo
        numElements = 0
        
        while numElements < k:
            if left >= 0 and right < n:
                if abs(arr[left] - x) <= abs(arr[right] - x):
                    lessThan.append(arr[left])
                    left -= 1
                elif abs(arr[left] - x) > abs(arr[right] - x):
                    greaterThan.append(arr[right])
                    right += 1
            elif left < 0:
                greaterThan.append(arr[right])
                right += 1
            else:
                lessThan.append(arr[left])
                left -= 1
            
            numElements += 1
        
        return lessThan[::-1] + greaterThan
                
                
