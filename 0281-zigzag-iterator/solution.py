class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.v1 = v1
        self.v2 = v2
        self.index1 = 0
        self.index2 = 0
        
        self.curList = 1

    def next(self):
        """
        :rtype: int
        """
        if self.curList == 1:
            if self.index1 < len(self.v1):
                result = self.v1[self.index1]
                self.curList = 2
                self.index1 += 1
                return result
            else:
                self.curList = 2
                result = self.v2[self.index2]
                self.index2 += 1
                return result
        if self.index2 < len(self.v2):
            result = self.v2[self.index2]
            self.curList = 1
            self.index2 += 1
            return result
        self.curList = 1
        result = self.v1[self.index1]
        self.index1 += 1
        return result
                
            
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return (self.index1 + self.index2) < len(self.v1) + len(self.v2)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
