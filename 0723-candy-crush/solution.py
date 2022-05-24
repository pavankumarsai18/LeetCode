class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
        n, m = len(board), len(board[0])
        
        def isValid(r, c):
            return (0 <= r < n) and (0 <= c < m)
        
        def oneStep():
            modified = False
            for r in range(n):
                for c in range(m):
                    if board[r][c] == 0:
                        continue
                    dr = 0
                    while isValid(r+dr, c) and abs(board[r+dr][c]) == abs(board[r][c]):
                        dr += 1
                    
                    dc = 0
                    while isValid(r, c+dc) and abs(board[r][c+dc]) == abs(board[r][c]):
                        dc += 1
                    
                    dr, dc = dr - 1, dc - 1
                    if dr >= 2 or dc >= 2:
                        modified = True
                        board[r][c] = -(abs(board[r][c]))

                    if dr >= 2:
                        while dr > 0:
                            if board[r+dr][c] > 0:
                                board[r+dr][c] *= -1
                            dr -= 1
                    
                    if dc >= 2:
                        while dc > 0:
                            if board[r][c+dc] > 0:
                                board[r][c+dc] *= -1
                            dc -= 1
                        
            for r in range(n):
                for c in range(m):
                    if board[r][c] < 0:
                        board[r][c] = 0
            c = 0
            r = n - 1
            
            while c < m:
                rowShift = [0 for _ in range(n)]
                shiftAmt = 0
                
                r = n - 1
                while r >= 0:
                    if board[r][c] == 0:
                        shiftAmt += 1
                    rowShift[r] = shiftAmt
                    r -= 1
                r = n - 1
                while r >= 0:
                    if board[r][c] != 0 and r + rowShift[r] < n:
                        board[r+rowShift[r]][c] = board[r][c]
                    r -= 1
                r = 0
                while r < shiftAmt:
                    board[r][c] = 0
                    r += 1
                c += 1
            return modified
        
        modified = True
        while modified == True:
            modified = oneStep()
            if not modified:
                break

        return board;
                    
            
