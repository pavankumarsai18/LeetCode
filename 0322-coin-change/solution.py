class Solution(object):
    
    def minCoins(self, coins, amount, dp):
        if amount in dp:
            return dp[amount]
        
        if amount < 0:
            dp[amount] = -1
            return -1
        
        if amount == 0:
            dp[amount] = 0
            return 0

        minimumCoins = float('inf')
        for coin in coins:
            res = self.minCoins(coins, amount-coin, dp) + 1
            if res > 0 and res < minimumCoins:
                minimumCoins = res
        
        if minimumCoins == float('inf'):
            minimumCoins = -1
        dp[amount] = minimumCoins
        return minimumCoins
                
        
        

    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = dict()
        return self.minCoins(coins, amount, dp)
