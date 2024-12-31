class Solution:
    def minimumBuckets(self, s: str) -> int:
        if s == 'H' or s[:2] == 'HH' or s[-2:] == 'HH' or 'HHH' in s:
            return -1
        return s.count('H') - s.count('H.H')
