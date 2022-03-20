class FreqStack(object):

    def __init__(self):
        self.freqCount = {}
        self.maxCount = -1
        self.stacks = {}
        
    def push(self, val):
        valCnt = 1 + self.freqCount.get(val, 0)
        if valCnt > self.maxCount:
            self.maxCount = valCnt
            self.stacks[self.maxCount] = []
        self.freqCount[val] = valCnt
        self.stacks[valCnt].append(val)
        
    def pop(self):
        val = self.stacks[self.maxCount].pop()
        self.freqCount[val] -= 1
        if not self.stacks[self.maxCount]:
            self.maxCount -= 1
        return val
        

        
# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
