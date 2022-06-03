class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        gates = set()
        n, m = len(rooms), len(rooms[0])
        
        gateVal = 0
        blockVal = -1
        
        inf  = 2147483647
        
        steps = [(-1,0),(1,0),(0,-1),(0,1)]
        
        def isValid(r, c):
            return 0 <= r < n and 0 <= c < m
        
        def bfs(pos):
            
            return
        
       
        
        # Do bfs search for each gate and update the rooms
        
        visited = set()
        Q = deque()
         # Add gates to set
        for i in range(n):
            for j in range(m):
                if rooms[i][j] == 0:
                    Q.append((i,j))
                    
        while Q:
            r, c = Q.popleft()
            for step in steps:
                dr, dc = step
                if isValid(r+dr, c+dc) and (rooms[r+dr][c+dc] != gateVal and rooms[r+dr][c+dc] != blockVal) and (r+dr, c+dc) not in visited:
                    rooms[r+dr][c+dc] = min(rooms[r+dr][c+dc], rooms[r][c] + 1)

                    visited.add((r+dr, c+dc))
                    Q.append((r+dr, c+dc))
        
        return
        
        
