class MovingAverage(object):

    def __init__(self, size):
        """
        :type size: int
        """
        self.maxSize = size
        self.curSize = 0
        self.deque = collections.deque()
        self.sum = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        if self.curSize == self.maxSize:
            first = self.deque.popleft()
            self.deque.append(val)
            self.sum -= first
            self.sum += val
            return (self.sum*1.0)/self.curSize
            
        self.deque.append(val)
        self.sum += val
        self.curSize += 1
        return (self.sum*1.0)/self.curSize
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
