class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        score = 0
        n, m  = len(nums), len(multipliers)
        dp = [0] * (m+1)
        
        for op in range(m-1, -1, -1):
            next_row = dp.copy()
            for left in range(op, -1, -1):
                right = n - 1 - op + left
                
                dp[left] = max(multipliers[op]*nums[left] + next_row[left+1], multipliers[op]*nums[right] + next_row[left])
            
        return dp[0]
