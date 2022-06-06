class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        
        n = len(s)
        
        sChars = defaultdict(int)
        
        for ch in s:
            sChars[ch] += 1
        for ch in t:
            if ch not in sChars:
                return False
            elif sChars[ch] <= 0:
                return False
            sChars[ch] -= 1
        
        for ch, count in sChars.items():
            if count != 0:
                return False
        return True
        
