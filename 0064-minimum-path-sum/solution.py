class Solution:
    def minPath(self, grid, i, j, memo):
        # print("r=",i,",j=",j,end=": ")
        # print(memo)
        if (i,j) in memo:
            return memo[(i,j)]
        
        if i == len(grid) - 1 and  j == len(grid[0]) - 1:
            memo[(i,j)] = grid[i][j]
            return grid[i][j]
        
        elif i >= len(grid) and j >= len(grid[0]):
            memo[(i,j)] = float('inf')

            return memo[(i,j)]

        result = float('inf')
        if (i + 1 < len(grid) and j < len(grid[0])):
            result = self.minPath(grid, i+1, j, memo)
        if (j + 1 < len(grid[0]) and i < len(grid))  :
            result = min(self.minPath(grid, i, j+1, memo), result)
        
        result += grid[i][j]
        memo[(i,j)] = result
        return result

    def minPathSum(self, grid: List[List[int]]) -> int:
        memo = dict()
        return self.minPath(grid, 0,0,memo)
