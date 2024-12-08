class Solution(object):
    def swimInWater(self, grid):
        n = len(grid)

        # Directions for 4 possible movements (up, down, left, right)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # Min-heap priority queue, starting with the top-left corner
        pq = [(grid[0][0], 0, 0)]  # (elevation, row, col)

        # Visited array to track the cells we have already processed
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        while pq:
            # Pop the cell with the smallest elevation
            time, x, y = heapq.heappop(pq)

            # If we reached the bottom-right corner, return the time
            if x == n - 1 and y == n - 1:
                return time

            # Explore the neighbors
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                    # We can only move to the neighbor if its elevation is <= the current time
                    visited[nx][ny] = True
                    # Push the neighbor into the heap with the maximum of current time and neighbor's elevation
                    heapq.heappush(pq, (max(time, grid[nx][ny]), nx, ny))

        return -1  # This should never happen if the input is valid


        
                    
                    
            
        
