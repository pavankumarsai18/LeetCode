class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) > len(t):
            return False
        if len(s) == len(t):
            return s == t
        
        sPtr = 0
        tPtr = 0
        
        while (tPtr < len(t) and sPtr < len(s)):
            if s[sPtr] == t[tPtr]:
                sPtr += 1
                tPtr += 1
            else:
                tPtr += 1
        return (sPtr == len(s) and tPtr <= len(t))
            
