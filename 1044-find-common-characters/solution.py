class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        d = {}
        for char in A[0]:
            if char not in d:
                d[char] = 1
            else:
                d[char] += 1
                
        for word in A[1:]:
            #create a dict of leter count pairs for the word
            l_c = {}
            for letter in word:
                if letter not in l_c:
                    l_c[letter] = 1
                else:
                    l_c[letter] += 1
            
            # compare the two dicts
            for key in d.copy():
                if key in l_c:
                    if l_c[key] < d[key]:
                        d[key] = l_c[key]
                else:
                    del d[key]
                
            
        result = []
        for key in d:
            for i in range(d[key]):
                result.append(key)
        return result
        
