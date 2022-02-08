class Solution(object):
    def isInterleave(self, A, B, C):
        if len(A) + len(B) != len(C):
            return False

        DP = [None for _ in range(len(B)+1)] 

        for i in range(len(A)+1):
            for j in range(len(B)+1):
                if i==0 and j==0:
                    DP[j] = True
                elif i == 0:
                    DP[j] = (DP[j-1] and (C[i+j-1] == B[j-1]))
                elif j == 0:
                    DP[j] = (DP[j] and (C[i+j-1] == A[i-1]))
                else:
                    DP[j] = (DP[j] and (C[i+j-1] == A[i-1])) or (DP[j-1] and (C[i+j-1] == B[j-1]))
        return DP[-1]
