class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        
        n = len(nums)
        dp = [[0 for _ in range(n)] for __ in range(n)]
        
        # dp[i][i]   = 0
        # dp[i][i+1] = 0
        # dp[i][i+2] = nums[i]*nums[i+1]*nums[i+2]
        # dp[i][j] = max(dp[i][k]+dp[k+1][j] + nums[i]*nums[k]*nums[j]) for k [i+1, j]

        for length in range(3, n+2):
            for i in range(0, n - length+1):
                j = i + length - 1
                dp[i][j] = float('-inf')
                for k in range(i+1, j):
                    cost = nums[i]*nums[k]*nums[j]
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + cost)
                    
        # for row in dp:
        #     print(row)
        
        return dp[0][n-1]
        
