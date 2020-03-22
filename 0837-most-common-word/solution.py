class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        S = set()
        for word in banned:
            S.add(word)
            
        punc = "!?',;."
        paragraph = paragraph.strip(punc)
        
        for w in paragraph:
            if w in punc:
                paragraph = paragraph.replace(w, ' ')
        
        paragraph = paragraph.replace(' ', '-')
        
        paragraph = paragraph.lower()
        words = paragraph.split('-')
        
        D = {}
        for word in words:
            if word == '':
                continue
            if word not in S:
                if word in D:
                    D[word] += 1
                else:
                    D[word] = 1
                    
        result = None
        for word in D:
            if result is None:
                result = word
            if D[word] > D[result]:
                result = word
        return result
        
        
