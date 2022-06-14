class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n,m = len(word1), len(word2)
        if m > n:
            m, n = n, m
            word1, word2 = word2, word1
        dp = [0]*(m+1)
        
        
        for i in range(n):
            new_dp = [0]*(m+1)
            for j in range(m):
                if word1[i] == word2[j]:
                    new_dp[j+1] = dp[j] + 1
                else:
                    new_dp[j+1] = max(dp[j+1], new_dp[j])
            dp = new_dp
    
        return n + m - 2*dp[m]
                    
                    
                    
        
