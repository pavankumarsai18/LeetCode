class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        if obstacleGrid[0][0]==1: return 0
        
        m,n = len(obstacleGrid),len(obstacleGrid[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j]==1: dp[i][j] = 0
        
        c = 1
        for i in range(m):
            if dp[i][0]<0: dp[i][0] = c
            else: c = 0
        
        c = 1
        for i in range(1,n):
            if dp[0][i]<0: dp[0][i] = c
            else: c = 0
        
        for i in range(1,m):
            for j in range(1,n):
                if dp[i][j]<0: dp[i][j] = dp[i-1][j] + dp[i][j-1]
                    
        return dp[m-1][n-1]
