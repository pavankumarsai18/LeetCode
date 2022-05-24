class Solution(object):
    def initBoard(self):
        self.diags           = set()
        self.antiDiags       = set()
        self.cols = set()
        self.numQueens       = 0
        # self.board = [['.' for _ in range(self.n)] for __ in range(self.n)]
    
    def isValid(self, r, c):
        return  (c not in self.cols) and (r+c not in self.diags) and (r - c not in self.antiDiags) 
    
    # def getBoard(self):
    #     ans = []
    #     for row in self.board:
    #         ans.append("".join(row))
    #     return tuple(ans)
    
    def printBoard(self):
        for row in self.board:
            print(row)
        print("COLS", self.cols)
        print("DIAGS", self.diags)
        print("ANTIDIAGS", self.antiDiags)
        
    def backtrack(self, r):
        # self.printBoard()
        
        if r == self.n:
            self.result += 1
            return
        
        for c in range(self.n):            
            if self.isValid(r, c):
                self.cols.add(c)
                self.diags.add(r+c)
                self.antiDiags.add(r-c)
                
                # self.board[r][c] = 'Q'
                
                self.backtrack(r+1)
                
                self.cols.remove(c)
                self.diags.remove(r+c)
                self.antiDiags.remove(r-c)
                # self.board[r][c] = "."
                
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.n = n
        self.result = 0

        self.initBoard()
        self.backtrack(0)
        
        return self.result
        
