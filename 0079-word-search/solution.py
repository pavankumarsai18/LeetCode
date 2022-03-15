class Solution(object):
    def isValid(self, board, index):
        x,y = index[0], index[1]
        
        if 0 > x or x >= len(board):
            return False
        if 0 > y or y >= len(board[0]):
            return False
        return True
    
    def matchWord(self, board, word, index, visited):
        if word == "":
            return True
        if self.isValid(board, index) == False:
            return False
        
        x,y = index[0], index[1]        
        # print(x,y, word)
        
        visited.add((x, y))

        if board[x][y] != word[0]:
            return False
        
        if board[x][y] == word:
            visited.add((x, y))
            return True
        
        results = []
        for dx in [-1,0,1]:
            for dy in [-1,0,1]:
                condition = (dx == 0 and dy != 0) or (dx != 0 and dy == 0)
                condition = condition and self.isValid(board, [x+dx,y+dy])
                condition = condition and (x+dx, y+dy) not in visited
                if condition:
                    visited.add((x+dx, y+dy))
                    result = self.matchWord(board, word[1:], [x+dx, y+dy], visited)
                    if result == False and (x+dx,y+dy) in visited:
                        visited.remove((x+dx,y+dy))
                    results.append(result)
        
        if len(results) > 0 and any(results):
            visited.add((x, y))
            return True
        visited.remove((x,y))
        return False
                    
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if word == "":
            return True
        
        if len(word) > len(board)*len(board[0]):
            return False
        
        indices = []
        chars = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    indices.append([i,j])
                chars.add(board[i][j])
        
        for w in word:
            if w not in chars:
                return False
            
        if len(word) == 1:
            if len(indices) > 0:
                return True
            return False
        
        visited = set()
        for index in indices:
            result = self.matchWord(board, word, index, visited)
            if result:
                return True
        return False
