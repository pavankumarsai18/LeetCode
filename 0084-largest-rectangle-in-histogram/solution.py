class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        n = len(heights)
        maxArea = 0
        stack = []
        
        for (i, h) in enumerate(heights):
            curIndex = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                maxArea = max(maxArea, height*(i - index))
                curIndex = index

            stack.append((curIndex, h))
        
        while stack:
            index, height = stack.pop()
            maxArea = max(maxArea, height*(n - index))
        
        return maxArea
                
        
        
