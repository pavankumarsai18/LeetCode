import copy

class Solution(object):   
    def solve(self, board):
        n = len(board)
        rows = [set() for _ in xrange(n)]
        cols = [set() for _ in xrange(n)]
        smallBoards = [set() for _ in xrange(n)]
        possibleVals = [[set() for _ in xrange(n)]  for __ in xrange(n)]

        allNums = set([str(x) for x in range(1, 10)])


        def fillElement(element, r, c):
            board[r][c] = element
            rows[r].add(element)
            cols[c].add(element)
            boardIndex = (r//3)*3 + (c//3)
            smallBoards[boardIndex].add(element)

            possibleVals[r][c] = element
            
            singleIndices = set()

            for i in xrange(n):
                if i != r and element in possibleVals[i][c]:
                    possibleVals[i][c].remove(element)
                    if len(possibleVals[i][c]) == 1:
                        singleIndices.add((i,c))


            for j in xrange(n):
                if j != c and element in possibleVals[r][j]:
                    possibleVals[r][j].remove(element)
                    if len(possibleVals[r][j]) == 1:
                        singleIndices.add((r, j))
            
            for index in singleIndices:
                x, y = index
                if len(possibleVals[x][y]) == 1:
                    element = possibleVals[x][y].pop()
                    fillElement(element, x, y)
            return 

        def isFilled(B):
            for i in range(n):
                for j in range(n):
                    if B[i][j] == '.':
                        return False
            return True

        # Initialize all the cols, rows, smallBoards, possibleVals
        for i in xrange(n):
            for j in xrange(n):
                if board[i][j] != '.':
                    rows[i].add(board[i][j])
                    cols[j].add(board[i][j])
                    possibleVals[i][j] = set(str(board[i][j]))

                    boardIndex = (i//3)*3 + (j//3)
                    smallBoards[boardIndex].add(board[i][j])


        for boardIndex in range(n):
            startRow = (boardIndex//3)*3
            startCol = (boardIndex%3)*3

            for i in xrange(startRow, startRow + 3):
                for j in xrange(startCol, startCol + 3):
                    if board[i][j] == '.':
                        possibleVal = allNums - rows[i] - cols[j] - smallBoards[boardIndex]
                        possibleVals[i][j] = possibleVal
                        if len(possibleVal) == 1:
                            fillElement(possibleVal.pop(), i, j)
                        elif len(possibleVal) == 0:
                            return None
                    
        # If the board is filled we return it
        if isFilled(board):
            return board

        copyBoard = copy.deepcopy(board)
        
        # we try to put some values and solve the board
        for i in xrange(n):
            for j in xrange(n):
                if len(possibleVals[i][j]) > 1:
                    for val in possibleVals[i][j]:
                        temp = copy.deepcopy(copyBoard)
                        temp[i][j] = val
                        result = self.solve(temp)
                        if result == None:
                            continue
                        if isFilled(result):
                            return result

                    return copyBoard
        return copyBoard


    def solveSudoku(self, board):
        ans = copy.deepcopy(board)
        ans = self.solve(ans)
        
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                board[i][j] = ans[i][j]
