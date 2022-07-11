class Solution:
    def axisIntersection(self, ax1:int, ax2: int,bx1:int, bx2:int):
        
        # No intersection
        if ax2 <= bx1:
            return 0
        if bx2 <= ax1:
            return 0
        
        if ax1 <= bx1 <= bx2 <= ax2:
            return bx2 - bx1
        if ax1 <= bx1 <= ax2 <= bx2:
            return ax2-bx1
        if bx1 <= ax1 <= bx2 <= ax2:
            return bx2 - ax1
        return ax2 - ax1
    
    def intersection(self, ax1:int, ay1:int, ax2: int, ay2:int, bx1:int, by1:int, bx2:int, by2:int):
        return self.axisIntersection(ax1, ax2, bx1, bx2)*self.axisIntersection(ay1, ay2, by1, by2)
            
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        total_area = (ax2-ax1)*(ay2-ay1) + (bx2 - bx1)*(by2-by1)
        
        # No intersection
        
        # A intersects B
        
        # B in A
        
        # B intersects A
        
        # A in B
        
        
        total_area -= self.intersection(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2)
        return total_area
