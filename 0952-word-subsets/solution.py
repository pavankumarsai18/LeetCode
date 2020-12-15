class Solution:
    def MakeDict(self, s):
        result = dict()
        for c in s:
            if c in result:
                result[c] += 1
            else:
                result[c] = 1
        return result
    
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        result = list()
        
        # Make a complete map
        Map = dict()
        for s in B:
            temp = self.MakeDict(s)
            for k in temp:
                if k not in Map:
                    Map[k] = temp[k]
                elif Map[k] < temp[k]:
                    Map[k] = temp[k]
    
        # O(A*len(Map))
        for word in A:
            d2 = self.MakeDict(word)
            isMatch = True
            for key in Map:
                if key not in d2 or d2[key] < Map[key]:
                    isMatch = False
                    break
            if isMatch == True:
                result.append(word)
        return result
            
