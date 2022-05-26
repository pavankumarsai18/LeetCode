class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        numOnes = 0
        while n:
            if n&1 == 1:
                numOnes +=1
            n = n >>1
        return numOnes
