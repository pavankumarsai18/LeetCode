class Solution:
    def numSquares(self, n: int) -> int:
        def isSquare(n:int)->int:
            sq = int(math.sqrt(n))
            return sq*sq == n
        
        
        while (n&3) == 0:
            n >>= 2
        
        if (n&7) == 7:
            return 4
        
        if isSquare(n):
            return 1
        
        i = 1
        while i*i <= n:
            if isSquare(n - i*i):
                return 2
            i += 1
        
        return 3
