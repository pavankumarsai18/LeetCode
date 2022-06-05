class Solution(object):
    def initBoard(self):
        self.diags           = set()
        self.antiDiags       = set()
        self.cols = set()
    
    def isValid(self, r, c):
        return  (c not in self.cols) and (r+c not in self.diags) and (r - c not in self.antiDiags) 
    
    def backtrack(self, r):        
        if r == self.n:
            self.result += 1
            return
        
        for c in range(self.n):            
            if self.isValid(r, c):
                self.cols.add(c)
                self.diags.add(r+c)
                self.antiDiags.add(r-c)
                                
                self.backtrack(r+1)
                
                self.cols.remove(c)
                self.diags.remove(r+c)
                self.antiDiags.remove(r-c)
                
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
        
