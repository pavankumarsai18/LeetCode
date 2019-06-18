class Solution:
    def __init__(self):
        self.r1 = 2
        self.r2 = 3
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        elif n == 3:
            return 3
        else:
            for i in range(4, n + 1):
                temp = self.r1
                self.r1 = self.r2
                self.r2 = temp + self.r2
            return self.r2

