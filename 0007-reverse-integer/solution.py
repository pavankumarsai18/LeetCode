class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        temp = x
        if temp < 0:
            x *= -1
        while x != 0:
            result += x % 10
            x //= 10
            if x > 0:
                result *= 10
                
        if temp < 0:
            result *= -1
            
        if result >= 2**31 or result < -1*(2**31):
            return 0
        return result
            
