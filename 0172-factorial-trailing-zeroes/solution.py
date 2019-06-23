class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n <= 4:
            return 0
        if n <= 9:
            return 1
        else:
            x = 5
            result = 0
            while n//x > 0:
                result += n//x
                x *= 5
            return result

            
