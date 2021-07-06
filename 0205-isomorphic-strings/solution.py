class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        if len(s) != len(t):
            return False
        
        if len(s) == 0 and len(t) == 0:
            return True
        
        mapCharsS = dict()
        mapCharsT = dict()
        
        for index in range(len(s)):
            if (s[index] not in mapCharsS) and (t[index] not in mapCharsT):
                mapCharsS[s[index]] = t[index]
                mapCharsT[t[index]] = s[index]
            elif (s[index] in mapCharsS):
                if mapCharsS[s[index]] == t[index]:
                    continue
                else:
                    return False
            elif (t[index] in mapCharsT):
                if mapCharsT[t[index]] == s[index]:
                    continue
                else:
                    return False
        
        return True
                
        
        
