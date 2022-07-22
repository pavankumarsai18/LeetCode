class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        def f(x):
            ans = 0
            r = 1
            for i in range(1, k+1):
                r *= x-i+1
                r //= i
                ans += r
                if ans >= n: break
            return ans

        lo, hi = 1, n
        while lo < hi:
            mi = (lo + hi) // 2
            if f(mi) < n:
                lo = mi + 1
            else:
                hi = mi
        return lo
