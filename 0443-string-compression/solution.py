class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        totalLen = 0
        
        rIndex = 0
        wIndex = 0
        
        while rIndex < len(chars):
            curChar = chars[rIndex]
            count   = 0
            
            while rIndex < len(chars) and chars[rIndex] == curChar:
                rIndex += 1
                count  += 1
            
            if count == 1:
                chars[wIndex] = curChar
                wIndex += 1
                totalLen += 1
            else:
                chars[wIndex] = curChar
                wIndex += 1
                strCount = str(count)
                
                for i in xrange(len(strCount)):
                    chars[wIndex] = strCount[i]
                    wIndex += 1
        
                totalLen += 1 + len(strCount)
                
        return totalLen
