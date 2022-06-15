class Solution:
    def numDecodings(self, text: str) -> int:
        # number of ways to split the encoded msg 
        # such that each item will be 1 <= <= 26 and no leading zeros
        n = len(text)
        
        prev = 1 if text[0] != '0' else 0
        secondPrev = 1 
        for i in range(2, n+1):
            cur = 0
            if text[i-1] != '0':
                cur = prev
            
            if i-2 >= 0 and 10 <= int(text[i-2:i]) <= 26:
                cur += secondPrev
            
            prev, secondPrev = cur, prev
        return prev
        
        
