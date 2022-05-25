# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.n = n
        
        possibleCandidate = 0
        
        for i in range(self.n):
            if knows(possibleCandidate, i):
                possibleCandidate = i
        
        if self.isCelebrity(possibleCandidate):
            return possibleCandidate
        return -1
        
    
    def isCelebrity(self, candidate):
        for i in range(self.n):
            if i == candidate:
                continue
            if (not knows(i, candidate)) or (knows(candidate, i)):
                return False
        return True
