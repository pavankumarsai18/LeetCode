class UnionFind(object):
    def __init__(self, items):
        self.items = items
        self.itemMap = {items[i]:i for i in range(len(items))}
        self.rank = [0 for _ in range(len(items))]
        self.parent = [i for i in range(len(items))]
        self.groups = set(self.parent)
        
    def find(self, item):
        index = self.itemMap[item]
        if self.parent[index] != index:
            parentItem = self.items[self.parent[index]]
            self.parent[index] = self.find(parentItem)
        return self.parent[index]
    
    def union(self, item1, item2):
        
        x, y = self.find(item1), self.find(item2)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            x,y = y,x
            
        if self.rank[x] >= self.rank[y]:
            self.parent[y] = x            
        
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
            
            self.groups.remove(y)
               
    
    def getNumIslands(self):
        return len(self.groups)
        
        
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        
        steps = [(-1,0),(1,0),(0,1),(0,-1)]
        visited = set()
        ones = list()
        # islands = None

        
        def isValid(x,y):
            return 0 <= x < len(grid) and 0 <= y < len(grid[0])
        
        def dfs(x,y):
            if (x,y) not in visited:
                visited.add((x,y))
                for step in steps:
                    dx, dy = step
                    if isValid(x+dx, y + dy) and grid[x+dx][y+dy] == '1':
                        # islands.union((x,y),(x+dx,y+dy))
                        dfs(x+dx,y+dy)  
                
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    ones.append((i,j))
                    
        islands = 0

        for one in ones:
            if one not in visited:
                x,y = one
                dfs(x,y)
                islands += 1
            
        return islands
            
        
        
