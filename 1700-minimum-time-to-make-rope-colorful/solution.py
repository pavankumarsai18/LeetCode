class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n         = len(colors)
        i, j      = 0, 0
        minCost = 0
        
        while i < n and j < n:
            total   = 0
            maxTime = 0
            
            while j < n and colors[i] == colors[j]:
                total  += neededTime[j]
                maxTime = max(maxTime, neededTime[j])
                j += 1
            
            minCost += total - maxTime
            i = j
        
        return minCost
