class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sub_array_sum = []
        n = len(nums)
        MOD = 1e9 + 7
        for i in range(n):
            cur_sum = 0
            for j in range(i, n):
                cur_sum += nums[j]
                cur_sum %= MOD
                sub_array_sum.append(cur_sum)
        
        sub_array_sum.sort()

        ans = 0
        for i in range(left - 1, right):
            ans += sub_array_sum[i]
            ans %= MOD
        return int(ans)

