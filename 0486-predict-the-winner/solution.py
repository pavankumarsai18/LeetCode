class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = nums[:]
        for size in range(1, n):
            for left in range(n - size):
                right = left + size
                dp[left] = max(nums[left] - dp[left + 1], nums[right] - dp[left])
        
        return dp[0] >= 0

