import math
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num < 0:
            return False
        if num == 1:
            return True
        if num == 0 or num == 2 or num == 3:
            return False
        if (math.log(num)/math.log(4)).is_integer():
            return True
        return False
        
