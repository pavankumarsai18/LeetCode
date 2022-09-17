class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        l = 1
        r = max(ribbons)
        
        while l <= r:
            ribbonSize = (l + r)//2
    
            numRibbons = sum(ribbon // ribbonSize for ribbon in ribbons)
                
            if numRibbons >= k:
                l = ribbonSize + 1
            else:
                r = ribbonSize - 1
                
        return r
            
