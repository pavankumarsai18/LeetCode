class Solution:
    def addOne(self, num:str)->str:
        result = ["0" for _ in range(8)]
        index = len(num) - 1
        carry = 1
        
        while index >= 0:
            newDigit = 0
            if num[index].isdigit():
                newDigit = int(num[index]) + carry
            else:
                newDigit = ord(num[index]) - ord('a') + 10 + carry
            
            if newDigit < 10:
                newDigit = str(newDigit)
                carry = 0
            elif newDigit < 16:
                newDigit = chr(ord('a') + newDigit - 10)
                carry = 0
            else:
                newDigit = str(newDigit - 16)
                carry = 1
            
            result[index] = newDigit
            
            index -= 1
                
        return "".join(result)
        
    def onesComplement(self, num: str)->str:
        result = ["0" for _ in range(8)]
        n      = len(result)
        index  = len(num) - 1
        for digit in num:
            result[n - index - 1] = digit
            index -= 1
        
        for i, digit in enumerate(result):
        
            newDigit = 15 
            
            if result[i].isdigit():
                newDigit -= int(result[i])
            else:
                newDigit -= (ord(result[i]) - ord('a') + 10)
            
            if newDigit < 10:
                result[i] = str(newDigit)
            else:
                result[i] = chr(ord('a') + newDigit - 10)
        return "".join(result)
        
    def twosComplement(self, num:str)->str:
        return self.addOne(self.onesComplement(num))
        
    def positiveHex(self, num:int)->str:
        result = []
        
        while num:
            digit = num%16
            
            if digit < 10:
                result.append(str(digit))
            else:
                result.append(chr(ord('a') + digit - 10))
                
            num //= 16
        
        result = result[::-1]
        return "".join(result)
        
    
    def toHex(self, num: int) -> str:
        if num < 0:
            num *= -1
            return self.twosComplement(self.positiveHex(num))
        elif num == 0:
            return "0"
        return self.positiveHex(num)
        
