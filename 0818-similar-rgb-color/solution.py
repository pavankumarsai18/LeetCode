class Solution(object):
    
    def similarRGB(self, color):
        """
        :type color: str
        :rtype: str
        """
        def getHex(s):
            if s.isdigit():
                return int(s)
            return ord(s) - ord('a') + 10
        
        def getVal(s):
            return getHex(s[0])*16 + getHex(s[1])
            
        def nearestDigit(val):
            minDigit = 0
            value = getVal(val)
            val1, val2 = value//17, int(math.ceil((value*1.0)/17))
            
            if abs(val1*17 - value)  < abs(val2*17 - value):
                minDigit = val1
            else:
                minDigit = val2
            
            if minDigit < 10:
                minDigit = str(minDigit)
            else:
                minDigit = chr(minDigit - 10 + ord('a'))
                
            return str(minDigit) + str(minDigit)
                            
        
        result = ["#"]
        for i in [1,3,5]:            
            result.append(nearestDigit(color[i:i+2]))
        return "".join(result)
        
        

