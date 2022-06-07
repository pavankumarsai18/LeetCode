class Solution(object):
    def trap(self, h):
        """
        :type height: List[int]
        :rtype: int
        """
        n                 = len(h)
        L, R              = 0, n-1
        leftMax, rightMax = h[L], h[R]
        totalWater        = 0
        while L < R:
            if leftMax < rightMax:
                L += 1
                leftMax = max(leftMax, h[L])
                totalWater += leftMax - h[L]
            else:
                R -= 1
                rightMax = max(rightMax, h[R])
                totalWater += rightMax - h[R]

        return totalWater
