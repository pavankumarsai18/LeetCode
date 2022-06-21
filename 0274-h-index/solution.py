class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        
        citations.sort()
        # index i
        # value v
        # all papers with atleast v is (n - i)
        # if (n-i) >= v:
        #    hindex = v
        
        h_index = 0
        for i in range(n):
            if citations[n-i-1] > i:
                h_index = i+1
            else:
                break
        return h_index
                
            
            
            
