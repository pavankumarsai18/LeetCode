class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        num_rows, num_cols = len(matrix), len(matrix[0])
        longestPath = [[0 for _ in range(num_cols)] for __ in range(num_rows)]
        
        
        def lengthIncreasingPath(matrix: List[List[int]], r:int, c: int):
            if longestPath[r][c] != 0:
                return longestPath[r][c]
            
            maxLength = 1
            for step in [(-1,0), (1,0), (0,1), (0,-1)]:
                dr, dc = step
                if 0 <= r + dr < num_rows and 0 <= c + dc < num_cols and matrix[r+dr][c+dc] > matrix[r][c]:
                    maxLength = max(maxLength, lengthIncreasingPath(matrix, r+dr, c+dc) + 1)
            
            longestPath[r][c] = maxLength
            return maxLength
    
        maxIncreasingPath = 1
        for r in range(num_rows):
            for c in range(num_cols):
                maxIncreasingPath = max(maxIncreasingPath, lengthIncreasingPath(matrix,r,c))
                
        
        return maxIncreasingPath
            
