class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        left, mid = float('inf'), float('inf')
        
        for num in nums:
            if num <= left:
                left = num
            elif num <= mid:
                mid = num
            else:
                return True
        return False
                
            
