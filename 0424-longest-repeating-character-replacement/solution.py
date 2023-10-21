class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        lo, hi = 0, 0
        n = len(s)
        charCount = defaultdict(int)
        maxFrequency = 0
        ans = 0
        
        while hi < n:
            charCount[s[hi]] += 1

            maxFrequency = max(maxFrequency, charCount[s[hi]])
            
            while lo < hi and (hi - lo + 1 - maxFrequency) > k:
                charCount[s[lo]] -= 1
                lo += 1
            
            ans = max(ans, hi - lo + 1)
            hi += 1

        return ans
