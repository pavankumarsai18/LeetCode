class TrieNode(object):
    def __init__(self, val):
        self.val = val
        self.children = [None for _ in range(26)]
        self.ended = False
    
    def endWord(self):
        self.ended = True
    
    def ends(self):
        return self.ended
    
    def add(self, val):
        index = ord(val) - ord('a')
        
        if self.children[index] == None:
            self.children[index] = TrieNode(val)
        
        return self.children[index]
    
    def hasChild(self, val):
        index = ord(val) - ord('a')
        return (self.children[index] != None)
    
    def getChild(self, val):
        index = ord(val) - ord('a')
        return self.children[index]    
    
    def getVal(self):
        return self.val
    
    def getChildren(self):
        return self.children

                
        
class Trie(object):

    def __init__(self):
        self.head = TrieNode("")
        

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        cur = self.head
        for ch in word:
            cur = cur.add(ch)
        cur.endWord()

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        cur = self.head
        for i in range(len(word)):
            ch = word[i]
            if cur.hasChild(ch):
                cur = cur.getChild(ch)
            else:
                return False
        
        return cur.ends()

    
    def startsWith(self, prefix):
        """
        :type prefix: str
        :rtype: bool
        """
        cur = self.head
        for i in range(len(prefix)):
            ch = prefix[i]
            if cur.hasChild(ch):
                cur = cur.getChild(ch)
            else:
                return False
        
        return True
        
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
