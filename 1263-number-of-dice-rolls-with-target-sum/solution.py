class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        mod = 10**9 + 7
        dp = [0]*(max(target, k)+1)
        
        for total in range(1, k + 1):
            dp[total] = 1
       
        for numDie in range(2, n+1):
            newDP = [0]*(max(target, k) + 1)
            for total in range(1, min(numDie*k, target)+1):
                for num in range(1, k+1):
                    if total-num > 0:
                        newDP[total] += dp[total - num]
                        # newDP[total] %= mod
                newDP[total] %= mod
            dp = newDP
        
        return dp[target]
                    
