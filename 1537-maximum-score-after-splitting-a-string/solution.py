class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        totalOnes = 0
        for i in xrange(len(s)):
            bit = s[i]
            if bit == '1':
                totalOnes += 1
        
        maxScore = float('-inf')
        onesCounted = 0
        zerosCounted = 0
        for i in xrange(len(s)-1):
            bit = s[i]
            if bit == '1':
                onesCounted += 1
            else:
                zerosCounted += 1
            score = zerosCounted + (totalOnes - onesCounted)
            maxScore = max(maxScore, score)
    
        return maxScore
        
