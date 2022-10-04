# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        
        visited = set()
        x, y = 0,0
        direction = 0
        deltaPos = [(-1,0),(0,1),(1, 0), (0,-1)]
        
        def dfs(x, y, cur):
            robot.clean()
            visited.add((x,y))
            for direction in range(cur, cur+4):
                dx, dy = deltaPos[direction%4]
                newX, newY = x+dx, y+dy
                if (newX, newY) not in visited and robot.move():
                    dfs(newX, newY, direction%4)
                robot.turnRight()
                
            robot.turnRight()
            robot.turnRight()
            robot.move()
            robot.turnRight()
            robot.turnRight()
        
        dfs(0,0,0)
        return

                
                
        
        
