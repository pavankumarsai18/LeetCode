class Solution:
    def __init__(self):
        self.memo = {}
    
    def isSubsequence(self, s: str, t: str) -> bool:
        
        key = s + ',' + t
        if key in self.memo:
            return self.memo[key]
        
        if s == t or (s == '' and len(t) > 0):
            self.memo[key] = True
            return True
                
        if len(t) < len(s) or (len(s) == len(t) and s != t):
            self.memo[key] = False
            return False
        
        if s[0] == t[0]:
            ans = self.isSubsequence(s[1:], t[1:]) or self.isSubsequence(s, t[1:])
            self.memo[key] = ans
            return ans
        
        self.memo[key] = self.isSubsequence(s, t[1:])
        return self.memo[key]
        
        
        

