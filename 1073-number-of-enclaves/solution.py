class Solution(object):        
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n,m = len(grid), len(grid[0])
        steps = [(-1,0), (0,-1),(0,1),(1,0)]
        visited = set()
        numOnes = 0

        def isValid(r, c):
            return (0 <= r < n) and (0 <= c < m)
    
        def dfs(x, y):
            if (x,y) in visited or grid[x][y] != 1:
                return
            
            visited.add((x,y))
            for step in steps:
                dx, dy = step
                if isValid(x+dx, y + dy) and grid[x+dx][y+dy] == 1:
                    dfs(x+dx, y+dy)
            return
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    numOnes += 1
        
        
        boundary = [(x,y) for x in range(n) for y in [0, m-1]]
        boundary = boundary + [(x,y) for y in range(m) for x in [0, n-1]]
        
        
        for item in boundary:
            x, y = item
            if grid[x][y] == 1 and (x,y) not in visited:
                dfs(x,y)
                if len(visited) == numOnes:
                    return 0

        return numOnes - len(visited)
                
        
            
                    

