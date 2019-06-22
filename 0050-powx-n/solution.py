class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1/(self.myPow(x, -1*n))
        elif n == 0:
            return 1
        elif n == 1:
            return x
        if n%2 == 0:
            X = self.myPow(x, n/2)
            return X*X
        else:
            X= self.myPow(x, n//2)
            return X*X*x
        
            
        
