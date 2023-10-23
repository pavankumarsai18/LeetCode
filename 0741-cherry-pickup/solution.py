class Solution:
    def findMaxCherries(self, grid, r1, c1, r2, memo):
        c2 = (r1 + c1 - r2)
        n = len(grid)
        def isValid(r, c):
            return 0 <= r < n and 0 <= c < n and grid[r][c] != -1

        if  not isValid(r1, c1) or not isValid(r2, c2):
            return -1*float('inf')
        
        if (r1, c1, r2) in memo:
            return memo[(r1, c1, r2)]

        if r1 == n - 1 and c1 == n - 1:
            return grid[r1][c1]

        cherries = 0
        if r1 == r2 and c1 == c2:
            cherries += grid[r1][c1]
        else:
            cherries += grid[r1][c1] + grid[r2][c2]
        
        f1 = self.findMaxCherries(grid, r1 + 1, c1, r2 + 1, memo)
        f2 = self.findMaxCherries(grid, r1, c1 + 1, r2 + 1, memo)
        f3 = self.findMaxCherries(grid, r1 + 1, c1, r2, memo)
        f4 = self.findMaxCherries(grid, r1, c1 + 1,  r2, memo)

        cherries += max(f1, f2, f3, f4)
        memo[(r1, c1, r2)] = cherries
        return cherries

    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        memo = dict()
        return max(0, self.findMaxCherries(grid, 0, 0, 0, memo))

    
