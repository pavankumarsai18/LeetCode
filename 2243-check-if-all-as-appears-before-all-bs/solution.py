class Solution:
    def checkString(self, s: str) -> bool:
        index = 0
        n     = len(s)
        while index < n and s[index] == 'a':
            index += 1
            
        while index < n and s[index] == 'b':
            index += 1
        
        return index == n
            
