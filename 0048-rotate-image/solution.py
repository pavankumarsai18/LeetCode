class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def transpose(matrix):
            n = len(matrix)

            for i in range(0, n):
                bottom_left = (n-1, i)
                top_right = (i, n-1)
                while bottom_left != top_right:
                    bottom_r, bottom_c = bottom_left
                    top_r, top_c = top_right
                    matrix[bottom_r][bottom_c], matrix[top_r][top_c] = matrix[top_r][top_c], matrix[bottom_r][bottom_c]

                    bottom_left = (bottom_r - 1, bottom_c)
                    top_right = (top_r, top_c - 1)
                

        def reverse(matrix):
            for row in matrix:
                for idx in range(0, len(row)//2):
                    row[idx], row[len(row) - idx - 1] = row[len(row) - idx - 1], row[idx]
        

        transpose(matrix)
        reverse(matrix)
        return
