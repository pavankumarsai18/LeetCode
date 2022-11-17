class Solution:
                
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:    
        # print(f"area1 A {(ax2 - ax1)*(ay2 - ay1)} area2 B {(bx2 - bx1)*(by2 - by1)} intersection {self.intersects(ax1, ax2, bx1, bx2)*self.intersects(ay1, ay2, by1, by2)}")
        def intersects(p1a:int, p1b:int, p2a:int, p2b:int) -> int:
            # p1_a p2_a p1_b p2_b
            if p1a <= p2a <= p1b <= p2b:
                return p1b - p2a
            # p2a p1a p2b p1b
            elif p2a <= p1a <= p2b <= p1b:
                return p2b - p1a
            # p1a p2a p2b p1b
            elif p1a <= p2a <= p2b <= p1b:
                return p2b - p2a
            # p2a p1a p1b p2b
            elif p2a <= p1a <= p1b <= p2b:
                return p1b - p1a
            return 0
        return (ax2 - ax1)*(ay2 - ay1) + (bx2 - bx1)*(by2 - by1) -(intersects(ax1, ax2, bx1, bx2)*intersects(ay1, ay2, by1, by2))
        
        
