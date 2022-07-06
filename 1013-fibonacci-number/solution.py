import numpy as np
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        
        A = np.array(([1,1],[1,0]))
        A = np.linalg.matrix_power(A, N-1)
        return A[0][0]
        
