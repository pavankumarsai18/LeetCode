class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min = []
        
    def push(self, x: int) -> None:
        if len(self.stack) == 0:
            self.stack.append(x)
            self.min.append(x)
        else:
            self.stack.append(x)
            if x <= self.min[len(self.min)-1]:
                self.min.append(x)

    def pop(self) -> None:
        result = self.stack.pop()
        if result == self.min[len(self.min)-1]:
            self.min.pop()

    def top(self) -> int:
        return self.stack[len(self.stack)-1]

    def getMin(self) -> int:
        return self.min[len(self.min)-1]    


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
