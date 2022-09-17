class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l = max(weights)
        r = sum(weights)
        
        
        def canShip(capacity):
            days_taken = 1
            cur_weight = 0
            
            for weight in weights:
                cur_weight += weight
                
                if cur_weight > capacity:
                    cur_weight = weight
                    days_taken += 1
            
                if days_taken > days:
                    return False
            
            return days_taken <= days
                
                
        
        while l < r:
            mid = l + (r-l)//2
            
            if canShip(mid):
                r = mid
            else:
                l = mid + 1
        
        return l
