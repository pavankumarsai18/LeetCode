class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        longestPalindrome = 0

        dp, dpPrev = [0]*n, [0]*n

        for left in range(n - 1, -1, -1):
            dp[left] = 1
            for right in range(left + 1, n):
                if s[left] == s[right]:
                    dp[right] = dpPrev[right - 1] + 2
                else:
                    dp[right] = max(dp[right-1], dpPrev[right])
            dpPrev = dp[:]

        return dp[n-1]
