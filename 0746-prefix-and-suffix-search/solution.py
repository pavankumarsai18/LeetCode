Trie = lambda: collections.defaultdict(Trie)
WEIGHT = False
class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.trie = Trie()
        
        for weight, word in enumerate(words):
            word += '#'

            for i,ch in enumerate(word):
                cur = self.trie
                cur[WEIGHT] = weight
                for j in range(i, 2*len(word)-1):
                    cur = cur[word[j%len(word)]]
                    cur[WEIGHT] = weight
                
        
        

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        cur = self.trie
        for letter in suffix + '#' + prefix:
            if letter not in cur:
                return -1
            cur = cur[letter]
        return cur[WEIGHT]
        
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
