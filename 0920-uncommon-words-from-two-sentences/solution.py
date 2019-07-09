class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        # return list(set(A.split(' ')) ^ set(B.split(' ')))
        d_A = {}
        uncommon_words = []
        i = 0
        while i < len(A):
            s = ""
            while i < len(A) and A[i] != " ":
                s += A[i]
                i += 1
            i += 1
            if s in d_A:
                d_A[s] += 1
            else:
                d_A[s] = 1
        #print(d_A)
        
        d_B = {}
        i = 0
        while i < len(B):
            s = ""
            while i < len(B) and B[i] != " ":
                s += B[i]
                i += 1
            i += 1
            if s in d_B:
                d_B[s] += 1
            else:
                d_B[s] = 1
        
        
        for key in d_A.copy():
            if key in d_B.copy():
                del d_A[key]
                del d_B[key]
        
        result = []
        for key in d_A:
            if d_A[key] == 1:
                result.append(key)
        for key in d_B:
            if d_B[key] == 1:
                result.append(key)
        
        return result
                
        
        
        
        
            
        
