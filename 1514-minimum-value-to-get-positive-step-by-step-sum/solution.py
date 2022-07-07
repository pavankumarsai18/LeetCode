class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        minSum = 0
        rollingSum = 0
        
        for num in nums:
            rollingSum += num
            if minSum > rollingSum:
                minSum = rollingSum
    
        return (1 - minSum) if minSum < 1 else 1
        
