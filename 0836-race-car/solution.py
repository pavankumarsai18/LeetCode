class Solution:
    def racecar(self, target: int) -> int:
        Q = collections.deque([(0,0,1)])
        visited = set()
        
        
        while Q:
            moves, pos, speed = Q.popleft()
            
            if pos == target:
                return moves
            
            if (pos, speed) in visited:
                continue
            
            else:
                visited.add((pos, speed))
                Q.append((moves + 1, pos + speed, speed*2))
                
                if (pos + speed > target and speed >0) or (pos + speed < target and speed < 0):
                    speed = -1 if speed > 0 else 1
                    Q.append((moves + 1, pos, speed))
        
