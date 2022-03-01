class WordDictionary(object):

    def __init__(self):
        self.wordSearch = [set() for _ in xrange(25)]
        self.falseSet = set()
    def addWord(self, word):
        """
        :type word: str
        :rtype: None
        """          
        if word in self.falseSet:
            self.falseSet.remove(word)
            
        self.wordSearch[len(word)-1].add(word)

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if word in self.wordSearch[len(word)-1]:
            return True
        validIndices = [i for i in xrange(len(word)) if word[i] != '.']
        if len(validIndices) == len(word):
            if word in self.falseSet:
                return False
        
        tempW = ""
        for index in validIndices:
            tempW += word[index]
        
            
        for w in self.wordSearch[len(word)-1]:
            temp = ""
            for index in validIndices:
                temp += w[index]
            if temp == tempW:
                self.wordSearch[len(word)-1].add(word)
                return True
        
        self.falseSet.add(word)
        return False
            
# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
