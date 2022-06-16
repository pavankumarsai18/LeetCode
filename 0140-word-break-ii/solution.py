class Solution:
    def wordBreak(self, text: str, wordDict: List[str]) -> List[str]:
        
        wordSet   = set(wordDict)
        minLength = min(len(word) for word in wordDict)
        maxLength = max(len(word) for word in wordDict)
        ans       = []
        
        lengths   = sorted(list(set(len(word) for word in wordDict)))
        
        def helper(start, cache):
            if start in cache:
                return cache[start]
            
            if start + minLength > len(text):
                return []
            
            if start + minLength == len(text):
                if text[start:] in wordSet:
                    cache[start] = [[text[start:]]]
                    return [[text[start:]]]
                else:
                    cache[start] = []
                    return []
            
            result = []
            for length in lengths:
                index = start + length
                word = text[start:start+length]
                if word in wordSet:
                    for possibility in helper(index, cache):
                        result.append([word] + possibility)
                            
                if index == len(text) and word in wordSet:
                    result.append([word])
                elif index >= len(text):
                    break
                
            cache[start] = result
            return result
        
        cache = defaultdict(list)
        sentences = helper(0, cache)
        for sentence in sentences:
            ans.append(" ".join(sentence))
        return ans
