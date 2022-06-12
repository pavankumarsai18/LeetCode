class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dictionary = set(wordDict)
        minLength  = min(len(word) for word in wordDict)
        def canBreak(string, cache, dictionary):
            n = len(string)

            if string in cache:
                return cache[string]
            elif string in dictionary:
                cache[string] = True
                return True
            elif n < minLength:
                cache[string] = False
                return False
            
            for i in range(1, n):
                canWordBreak = canBreak(string[:i], cache, dictionary)
                canWordBreak = canWordBreak and canBreak(string[i:], cache, dictionary)
                if canWordBreak:
                    cache[string] = True
                    return True
            cache[string] = False
            return False
        
        return canBreak(s, {}, dictionary)
