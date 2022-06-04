class Solution:
    
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        if n == 1:
            return [["Q"]]
        
        self.n         = n
        self.result    = []
        self.numQueens = 0
       
        def canAddSafely(r, c):
            diag = r + c
            antiDiag = r - c
            
            safe = (c not in self.cols)
            safe = safe and (diag not in self.diags)
            safe = safe and (antiDiag not in self.antiDiags)
            
            return safe
        
        def addQueen(r, c):
            self.board[r][c] = 'Q'
            self.numQueens += 1

            self.antiDiags.add(r-c)
            self.diags.add(r+c)
            self.cols.add(c)
        
        def deleteQueen(r, c):
            self.board[r][c] = '.'
            self.numQueens -= 1

            self.antiDiags.remove(r-c)
            self.diags.remove(r+c)
            self.cols.remove(c)
        
        def printBoard():
            for row in self.board:
                print(row)
            print("\n\n")
        
        def solve():
            for c in range(self.n):
                if canAddSafely(self.row, c):
                    addQueen(self.row, c)
                    
                    if self.row == self.n - 1 and self.numQueens == self.n:
                        self.result.append(["".join(row) for row in copy.deepcopy(self.board)])
                    
                    elif self.row != self.n-1:
                        self.row += 1
                        solve()
                        self.row -= 1
                    
                    deleteQueen(self.row, c)
                    
        
        for i in range(self.n):
            self.cols, self.diags, self.antiDiags = set(), set(), set()        
            self.board = [["."]*self.n for _ in range(self.n)]
            self.numQueens = 0
            self.row = 0
            
            addQueen(0, i)
            
            self.row = 1
            
            solve()
            
            
        return self.result
        
        
