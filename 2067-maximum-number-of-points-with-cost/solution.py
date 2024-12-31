class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        rows, cols = len(points), len(points[0])
        previous_row = points[0]

        for row in range(1, rows):
            left_max    = [0 for _ in range(cols)]
            right_max   = [0 for _ in range(cols)]
            current_row = [0 for _ in range(cols)]
            left_max[0] = previous_row[0]
            for col in range(1, cols):
                left_max[col] = max(previous_row[col], left_max[col-1]-1)
            
            right_max[-1] = previous_row[-1]
            for col in range(cols - 2, -1, -1):
                right_max[col] = max(right_max[col+1] - 1, previous_row[col])
            
            for col in range(cols):
                current_row[col] = max(left_max[col], right_max[col]) + points[row][col]
            
            previous_row = current_row
        
        return max(previous_row)
