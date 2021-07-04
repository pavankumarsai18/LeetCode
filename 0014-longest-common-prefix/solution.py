class Node:
    def __init__(self):
        self.letter = ""
        self.child = list()
        self.count = 0

    def __init__(self, letter):
        self.child = list()
        self.count = 0
        self.letter = letter

    def addChild(self, letter):

        for i in range(len(self.child)):
            if self.child[i].letter == letter:
                self.child[i].count += 1
                return i

        n = Node(letter)
        self.child.append(n)
        self.child[-1].count += 1
        return len(self.child) - 1

class Trie:
    def __init__(self):
        self.n = Node('')
        self.numStrings = 0

    def addString(self, string):
        self.numStrings += 1
        self.n.count = self.numStrings

        if string != "":
            curNode = self.n
            for char in string:
                index = curNode.addChild(char)
                curNode = curNode.child[index]
        return

    def longestPrefix(self):
        curNode = self.n
        commonPrefix = ""

        while len(curNode.child) == 1 and curNode.child[0].count == self.numStrings:
            commonPrefix += curNode.child[0].letter
            curNode = curNode.child[0]

        return commonPrefix
    
class Solution(object):

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        t = Trie()
        for string in strs:
            t.addString(string)
        
        return t.longestPrefix()
        
