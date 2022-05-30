class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == 0:
            return 0
        
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        
        is_negative = False
        
        if (dividend < 0)^(divisor < 0):
            is_negative = True
        
        dividend, divisor = abs(dividend), abs(divisor)
        quotient = 0
        
        for i in reversed(range(dividend.bit_length() - divisor.bit_length() + 1)):
            if dividend - (divisor << i) >= 0:
                quotient |= (1<<i)
                dividend -= (divisor<<i)
        
        if is_negative:
            quotient *= -1
        
        return quotient
            
        
        
            
