class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        length = len(board)
        board.reverse()

        def squareToPos(square):
            r = (square - 1)//length
            c = (square - 1) %length

            if r & 1:
                c = length - 1 - c
            
            return [r, c]

        queue = deque()
        queue.append([1, 0])
        visit = set()

        while queue:
            square, moves = queue.popleft()
            for roll in range(1, 7):
                nextSquare = square + roll
                r, c = squareToPos(nextSquare)
                if board[r][c] != -1:
                    nextSquare = board[r][c]
                
                if nextSquare == length * length:
                    return moves + 1

                if nextSquare not in visit:
                    visit.add(nextSquare)
                    queue.append([nextSquare, moves + 1])
        
        return -1
