class Solution:
    
    def knightProbability(self, n: int, k: int, row: int, col: int) -> float:
        # get all steps for a knight
        steps = [(1,2),(-1,2),(1,-2),(-1,-2),(2,1),(-2,1),(-2,-1),(2,-1)]
        
        # Square represents the probability that a knight is on the chess board
        probSquare           = [[0]*n for _ in range(n)]
        
        # Since the knight is initially on (row, col) the probavility is 1
        probSquare[row][col] = 1
                
        # Iterate for k moves
        for move in range(1, k+1):
            # initialize new prob square
            newProbSquare = [[0]*n for _ in range(n)]
            
        #for each position in chessboard sum the probaility to get to the position
        #since each move is uniformly and randmly made the probability should 
        #be muliplied by 1/8 (0.125)
        
#prob(chess[k] [x][y] = sum(1/8 * prob(chess[k-1] [x+dx][y+dy]))) for each step   
            
            for x in range(n):
                for y in range(n):
                    for step in steps:
                        dx, dy = step
                        if 0 <= (x+dx) < n and 0 <= (y+dy) < n:
                            newProbSquare[x][y] += (0.125*probSquare[x+dx][y+dy])
            
            probSquare = newProbSquare

        # At the end we sum the probailities in the chess board
        ans = sum(sum(row) for row in probSquare)
                
        return ans
