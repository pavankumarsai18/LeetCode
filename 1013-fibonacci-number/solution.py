class Solution:
    def __init__(self):
        self.a = 1
        self.b = 2
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        elif N == 1:
            return 1
        elif N == 2:
            return 1
        elif N == 3:
            return 2
        else:
            for i in range(4, N + 1):
                temp = self.a
                self.a = self.b
                self.b = self.b + temp
            return self.b
            
        
