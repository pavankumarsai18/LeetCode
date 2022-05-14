class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        startStation = 0
        totalGas     = 0
        curTank = 0 
        for i in range(len(gas)):
            totalGas += gas[i] - cost[i]
            curTank += gas[i] - cost[i]
            if curTank < 0:
                startStation = i + 1
                curTank = 0
        
        return startStation if totalGas >= 0 else -1
        
