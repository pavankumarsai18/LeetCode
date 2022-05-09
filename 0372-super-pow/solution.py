class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        
        modVal = 1337
        a %= modVal
        
        if a == 1 or a == 0:
            return a

        
        
        power = ""
        for digit in b:
            power += str(digit)
        power = int(power)
        
        power %= 1140 # Eluers theorem
        
        bitPower = ""
        
        while power:
            bitPower += str(power&1)
            power >>= 1
        
        bitPower = bitPower[::-1]        
        
        
        result = 1
        modPowers = a%modVal
        for i in xrange(len(bitPower)-1,-1,-1):
            if bitPower[i] == '1':
                result = (result*modPowers)%modVal
            modPowers = (modPowers*modPowers)%modVal 
        return result
        
            
            
            
            
