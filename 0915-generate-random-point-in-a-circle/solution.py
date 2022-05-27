class Solution(object):

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        
        self.radius = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self):
        """
        :rtype: List[float]
        """

        r     = self.radius*sqrt(random.random())
        theta = random.random()*2*math.pi
        return [r*math.cos(theta)+self.x, r*math.sin(theta)+self.y]
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
