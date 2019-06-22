import math
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        
        while n != 0:
            n /= 2
            if math.floor(n) != n:
                return False
            if n == 1:
                return True
        return False
