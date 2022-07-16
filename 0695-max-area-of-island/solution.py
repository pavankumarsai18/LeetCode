class UnionFind(object):
    def __init__(self):
        self.n       = 0
        self.items   = []
        self.itemMap = defaultdict(int)
        self.parent  = []
        self.rank    = []
    
    def addItem(self, item):
        if item not in self.itemMap:
            self.items.append(item)
            self.itemMap[item] = self.n
            self.parent.append(self.n)
            self.rank.append(0)
            self.n += 1
    
    def findItem(self, item):
        if item in itemMap:
            return self.find(self.itemMap[item])

    def find(self, index):
        if self.parent[index] != index:
            self.parent[index] = self.find(self.parent[index])
            return self.parent[index]
        return index
        
    def unionItem(self, item1, item2):
        if item1 not in self.itemMap:
            self.addItem(item1)
        if item2 not in self.itemMap:
            self.addItem(item2)
        
        self.union(self.itemMap[item1], self.itemMap[item2])
        return
    
    def union(self, itemIndex1, itemIndex2):
        group1, group2 = self.find(itemIndex1), self.find(itemIndex2)
        
        if group1 == group2:
            return
        
        if self.rank[group1] < self.rank[group2]:
            group1, group2 = group2, group1
        
        self.parent[group2] = group1
        self.rank[group1] += 1
        return
    
    def getMaxItems(self):
        numItems = defaultdict(int)
        maxNum   = 0
        for item in range(self.n):
            group = self.find(item)
            numItems[group] += 1
            maxNum = max(maxNum, numItems[group])
        return maxNum
            
        
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        steps = [(-1,0),(0,1),(0,-1),(1,0)]
        n, m = len(grid), len(grid[0])
        islands = UnionFind()
        
        def isValid(r, c):
            return 0 <= r < n and 0 <= c < m
        
        for r in range(n):
            for c in range(m):
                if grid[r][c] == 1:
                    islands.addItem((r,c))
                    for step in steps:
                        dr, dc = step
                        if isValid(r+dr, c+dc) and grid[r+dr][c+dc] == 1:
                            islands.unionItem((r, c), (r+dr, c+dc))
                            
        return islands.getMaxItems()
        
