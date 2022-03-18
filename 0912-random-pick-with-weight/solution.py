class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        total = sum(w)
        temp = [(w[i]*1.0)/total for i in xrange(len(w))]
        self.prob = [None for _ in xrange(len(temp))]
        
        for i in xrange(len(self.prob)):
            if i == 0:
                self.prob[i] = (0, temp[i])
            else:
                temp[i] += temp[i-1]
                self.prob[i] = (temp[i-1], temp[i])
        
    
    def binarySearch(self, value):
        lo = 0
        hi = len(self.prob) - 1
        mid = hi
        while hi >= lo:
            mid = (lo + hi)//2
            lowerBound, higherBound = self.prob[mid]
            if lowerBound <= value < higherBound:
                return mid
            elif value >= higherBound:
                lo = mid + 1
            elif lowerBound > value:
                hi = mid - 1
        return mid
                
    def pickIndex(self):
        """
        :rtype: int
        """
        rand = random.random()
        
        return self.binarySearch(rand)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
