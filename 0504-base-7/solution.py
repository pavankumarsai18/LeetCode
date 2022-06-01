class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        
        result = []
        
        is_negative = (True) if num < 0 else False
        num = num if num >= 0 else -1*num
        
        while num:
            remainder = num%7
            result.append(str(remainder))
            num //= 7
            
        if is_negative:
            result.append('-')
            
        return "".join(reversed(result))
