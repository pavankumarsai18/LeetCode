class Solution(object):
    def getShapeOfIsland(self, island):
        shape = []
        island = sorted(list(island))
        length = len(island)
        
        curIndex, skipAmt  = 0, 0
        prevCol   = island[curIndex][1]
        
        while curIndex < length:
            curRow, curCol = island[curIndex]
            index  = curIndex
            rowLen   = 0

            while index < length and island[index][0] == curRow:
                index += 1
                rowLen  += 1

            shape.append((rowLen ,curCol - prevCol))
            prevCol = curCol
            curIndex = index
        return shape
    
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        steps = [(-1,0),(1,0),(0,-1),(0,1)]
        visited = set()
        
        n,m = len(grid),len(grid[0])

        def isValid(r, c):
            return (0 <= r < n) and (0 <= c < m)
        
        def dfs(r,c, visited):
            if (r,c) in visited:
                return
            
            visited.add((r,c))
            grid[r][c] = 0
            
            for step in steps:
                dr, dc = step
                if isValid(r+dr, c+dc) and grid[r+dr][c+dc] == 1:
                    dfs(r+dr, c+dc, visited)
            return
        

            
        ones    = []
        
        for r in xrange(n):
            for c in xrange(m):
                if grid[r][c] == 1:
                    ones.append((r,c))
        
        
        distinctIslands = set()
        for one in ones:
            r, c = one
            if grid[r][c] == 0:
                continue
                
            island = set()
            dfs(r, c, island)
            
            islandShape = self.getShapeOfIsland(island)
            distinctIslands.add(tuple(islandShape))
            
            
    
        return len(distinctIslands)
            
        
            
            
        
        
        
        
        
