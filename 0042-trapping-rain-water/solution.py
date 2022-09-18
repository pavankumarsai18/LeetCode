class Solution:
    def trap(self, height: List[int]) -> int:
        
        totalWater   = 0
        
        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        
        
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                totalWater += leftMax - height[l]
                
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                totalWater += rightMax - height[r]
        
        return totalWater
