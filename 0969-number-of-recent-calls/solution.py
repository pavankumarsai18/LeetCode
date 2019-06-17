
class RecentCounter:
    def __init__(self):
        self.queue = []

    def push(self, value):
        self.queue.insert(0, value)
        
    def pop(self):
        x = self.queue[len(self.queue) - 1]
        del self.queue[len(self.queue) - 1]
        return x
    
    def top(self):
        if not self.isEmpty():
            return self.queue[len(self.queue) - 1]
            
    def check(self, t):
        while not self.isEmpty() and self.top() + 3000 < t:
            self.pop()

    
    def isEmpty(self):
        return not bool(len(self.queue))
    
    def ping(self, t: int) -> int:
        #print(self.queue)
        if self.isEmpty():
            self.push(t)
            return 1
        else:
            self.check(t)
            self.push(t)
            return len(self.queue)
# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
