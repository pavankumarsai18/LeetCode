class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = {}
        def dfs(index):
            if index <= 0:
                return 0
            if index in memo:
                return memo[index]
            memo[index] = min(dfs(index-1), dfs(index - 2)) + cost[index-1]
            return memo[index]

        return min(dfs(len(cost)), dfs(len(cost) - 1))
