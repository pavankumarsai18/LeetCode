class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if k == len(s):
            return True
        elif k > len(s):
            return False
        
        charCount = [0 for _ in range(26)]
        
        for c in s:
            charCount[ord(c) - ord('a')] += 1
        
        midAligned = 0
        for c in charCount:
            if c%2 == 1:
                midAligned += 1
        
        if midAligned <= k:
            return True
        return False
        
        
        
        
