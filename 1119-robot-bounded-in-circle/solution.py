class Solution(object):
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """

        # L --> N -> E -> S -> W
        # R --> N -> W -> S -> E
        
        netMovement = 0
        netDirection = 0
        
        L = ["N", "E", "S", "W"]
        R = ["N", "W", "S", "E"]
        
        LdirMap = {"N":0, "E":1, "S":2, "W":3}
        RdirMap = {"N":0, "W":1, "S":2, "E":3}
        
        curPos = (0,0)
        curDir = "N"
        
        for move in instructions:
            if move == "G":
                if curDir == "N":
                    curPos = (curPos[0], curPos[1] + 1)
                elif curDir == "E":
                    curPos = (curPos[0] + 1, curPos[1])
                elif curDir == "W":
                    curPos = (curPos[0] - 1, curPos[1])
                else:
                    curPos = (curPos[0], curPos[1] -1)
            elif move == "L":
                curDir = L[(LdirMap[curDir] + 1)%4]
                
            elif move == "R":
                curDir = R[(RdirMap[curDir] + 1)%4]
        
        
        return curPos == (0,0) or (curDir != "N")
