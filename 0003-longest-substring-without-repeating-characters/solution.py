class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lastSeen = dict()
        ans = 0
        j = 0
        for i, ch in enumerate(s):
            if ch in lastSeen:
                j = max(j, lastSeen[ch])
            ans = max(ans, i - j + 1)
            lastSeen[ch] = i+1
            
        return ans
