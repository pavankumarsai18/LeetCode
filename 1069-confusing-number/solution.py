class Solution(object):
    def confusingNumber(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return False

        result = 0
        copy = n
        while n != 0:
            digit = n%10
            if digit == 2 or digit == 3 or digit == 4 or digit == 5 or digit == 7:
                return False
            else:
                newDigit = digit
                if digit == 6:
                    newDigit = 9
                elif digit == 9:
                    newDigit = 6
                
                result += newDigit
                if n >= 10:
                    result *= 10
            n >>= 1
            n //= 5

        return result != copy
                
