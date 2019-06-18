class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 0 or num == 1 or num == 4:
            return True
        elif num == 2 or num == 3:
            return False
        else:
            hi = num
            lo = 0
            mid = (hi + lo)//2
            prev_mid = None
            while hi > lo:
                # print(mid)
                if mid*mid < num:
                    lo = mid
                    mid = (lo + hi)//2
                elif mid*mid > num:
                    hi = mid
                    mid = (lo + hi)//2
                elif mid*mid == num:
                    return True
                if prev_mid == mid:
                    return False
                prev_mid = mid

