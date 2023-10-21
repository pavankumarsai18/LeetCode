class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(s)

        tCount = {}

        for char in t:
            tCount[char] = tCount.get(char, 0) + 1
        
        charCount = {}

        lo = 0
        res_lo, res_hi = -1, -1
        ans_len = float('inf')

        have = 0
        need = len(tCount)

        for hi in range(len(s)):
            charCount[s[hi]] = charCount.get(s[hi], 0) + 1

            if s[hi] in tCount and charCount[s[hi]] == tCount[s[hi]]:
                have += 1

            while have == need:
                if (hi - lo + 1) < ans_len:
                    res_lo, res_hi = lo, hi
                    ans_len = hi - lo + 1
                
                charCount[s[lo]] -= 1
                if s[lo] in tCount and tCount[s[lo]] > charCount[s[lo]]:
                    have -= 1
                lo += 1

        if ans_len == float('inf'):
            return ""
        return s[res_lo:res_hi+1]





                



