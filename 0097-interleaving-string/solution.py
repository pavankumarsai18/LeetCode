class Solution:
    def isInterleave(self, A: str, B: str, C: str) -> bool:
        if len(A) + len(B) != len(C):
            return False
        
        DP = [True]*(len(B)+1)
        
        for i in range(len(A)+1):
            for j in range(len(B)+1):
                if i == 0 and j == 0:
                    DP[j] = True
                elif i == 0:
                    DP[j] = DP[j - 1] and (C[i+j-1] == B[j-1])
                elif j == 0:
                    DP[j] = DP[j] and (C[i+j-1] == A[i-1])
                else:
                    DP[j] = (DP[j - 1] and C[i+j-1] == B[j-1]) or (DP[j] and C[i+j-1] == A[i-1]) 
                    
        return DP[-1]
                
        
        
