class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        lps = [0]*n
        
        for i in range(1, n):
            j = lps[i-1]
            
            while j and s[i] != s[j]:
                j = lps[j-1]
            
            if s[i] == s[j]:
                j += 1
                
            lps[i] = j
        
        return (lps[-1] != 0 and (lps[-1]%(n-lps[-1]) == 0))
