class UnionFind(object):
    def __init__(self, items):
        self.items = items
        
        self.itemMap = {items[i]:i for i in xrange(len(items))}
        self.parent = [i for i in xrange(len(items))]
        self.rank = [0 for _ in xrange(len(items))]
        

    def find(self, item):
        if item not in self.itemMap:
            return -1
        
        index = self.itemMap[item]
        if self.parent[index] != index:
            self.parent[index] = self.find(self.items[self.parent[index]])
        
        return self.parent[index]
    
    def union(self, item1, item2):
        if item1 not in self.itemMap or item2 not in self.itemMap:
            return
        
        index1, index2 = self.find(item1), self.find(item2)
        
        if self.items[index1] > self.items[index2]:
            index1, index2 = index2, index1

        if self.rank[index1] == self.rank[index2]:
            self.rank[index1] += 1
            self.parent[index2] = index1
        else:                
            self.parent[index2] = index1
        
    def getGroup(self, item):
        index = self.find(item)
        return self.items[index]
        
        
class Solution(object):
    def smallestEquivalentString(self, s1, s2, baseStr):
        charItems = list(set(s1).union(set(s2)))
        
        equivalence = UnionFind(charItems)
        
        n = len(s1)
        
        for i in range(n):
            if s1[i] != s2[i]:
                equivalence.union(s1[i], s2[i])
        
        # smallestEquiv = dict()
        # for char in charItems:
        #     smallestEquiv[char] = equivalence.getGroup(char)
        
        result = ""
        for char in baseStr:
            if equivalence.find(char) == -1:
                result += char
            else:
                result += equivalence.getGroup(char)
        return result
            
        
        
        
