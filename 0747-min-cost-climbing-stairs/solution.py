class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        firstStep  = 0
        secondStep = 0
        for i in xrange(2, len(cost)+1):
            firstStep, secondStep = min(cost[i-1] + firstStep, cost[i-2] + secondStep), firstStep 
            
        return firstStep
