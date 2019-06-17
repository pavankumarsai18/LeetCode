class Solution:
    def mySqrt(self, x: int) -> int:
        hi = x
        lo = 0
        mid = (hi + lo)//2
        if x <= 1:
            return x
        elif x == 2:
            return 1
        while hi > lo:
            # print(hi, mid, lo)
            if mid*mid > x:
                hi = mid
                mid = (hi + lo)//2
            elif mid*mid < x and (mid+1)*(mid+1) <= x:
                lo = mid
                mid = (hi+lo)//2
            elif mid*mid <= x and (mid+1)*(mid+1) > x:
                return mid
        
