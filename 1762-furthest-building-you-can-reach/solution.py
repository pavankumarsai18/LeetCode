class Solution:
    def isReachable(self, building: int, bricks:int, ladders:int)->bool:
        for climb in self.climbs:
            bricks_needed, index = climb
            if index > building:
                continue
                
            if bricks_needed <= bricks:
                bricks -= bricks_needed
            elif ladders >= 1:
                ladders -= 1
            else:
                return False
        return True
        
        
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        self.bricks  = bricks
        self.ladders = ladders
        
        
        self.climbs = []
        for i in range(n-1):
            building_height     = heights[i]
            next_builing_height = heights[i+1]
            
            climb_height = next_builing_height-building_height
            if climb_height > 0:
                self.climbs.append((climb_height, i+1))
        
        self.climbs.sort(key=lambda x: x[0])
   
        lo = 0
        hi = n - 1
        
        while lo < hi:
            mid = lo + (hi - lo + 1)//2

            if self.isReachable(mid, bricks, ladders):
                lo = mid
            else:
                hi = mid - 1
        # at the end of while loop lo will be equal to hi
        # so we can return either hi or lo
        return lo
        
    
