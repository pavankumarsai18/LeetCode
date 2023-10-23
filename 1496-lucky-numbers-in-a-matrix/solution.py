class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_rows = [min(row) for row in matrix]
  
        ans = list()
        m, n = len(matrix), len(matrix[0])

        max_col = []
        for c in range(n):
            max_col.append(max([matrix[r][c] for r in range(m)]))
        
        return list(set(min_rows).intersection(set(max_col)))
    


