class KMP:
    def __init__(self, string, pattern):
        self.string = string
        self.pattern = pattern
    
    def computeLPS(self):
        '''Computes the Longest proper Prefix that is also a Suffix'''
        lps = [0 for _ in range(len(self.pattern))]

        length, index = 0,1

        while index < len(self.pattern):
            if self.pattern[length] == self.pattern[index]:
                length += 1
                lps[index] = length
                index += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                elif length == 0:
                    lps[index] = 0
                    index += 1

        return lps
    
    def KMP(self):
        n, m = len(self.string), len(self.pattern)
        if m == 0:
            return 0
        if n == 0:
            return -1
        
        elif n == m and self.string == self.pattern:
            return 0
            
        lps = self.computeLPS()

        i, j = 0, 0

        while i < n:
            if self.string[i] == self.pattern[j]:
                i, j = i + 1, j + 1
            else:
                if j != 0:
                    j = lps[j - 1]
                elif j == 0:
                    i += 1
            if j == m:
                return i - m
        return -1


class Solution(object):
    def strStr(self, haystack, needle):
        kmp = KMP(haystack, needle)
        return kmp.KMP()
        
        
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
