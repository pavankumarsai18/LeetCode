class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0
        n = len(prices)
        
        for i in range(1, n):
            profit = prices[i] - minPrice
            maxProfit = max(maxProfit, profit)
            minPrice = min(minPrice, prices[i])
        
        return maxProfit
