class Solution(object):
    def ambiguousCoordinates(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        def isValid(x, pointAdded):
            if pointAdded and x[-1] == '0':
                return False
                
            if pointAdded and float(x) != int(float(x)):
                return True
            elif not pointAdded:
                return True
            return False
            
        s = s[1:-1]
        result = set()
        for i in xrange(len(s)):
            x = s[:i]
            y = s[i:]
            
            # print(x, y)
            xZero = False
            yZero = False
            
            
            j = 0
            if j < len(x) and x[j] == '0':
                xZero = True                    
                
            
            k = 0
            if k < len(y) and y[k] == '0':
                yZero = True
                            
            # print(xZero, yZero)
            
            while j < len(x):
                k = 0
                while k < len(y):
                    newX = x[:j] + "." + x[j:]
                    newY = y[:k] + "." + y[k:]
                    xpointAdded = True
                    ypointAdded = True
                    if xZero:
                        if len(x) == 1:
                            newX = x
                            xpointAdded = False
                        else:
                            newX = x[:1] + "." + x[1:]
                            
                    if yZero:
                        if len(y) == 1:
                            newY = y
                            ypointAdded = False
                        else:
                            newY = y[:1] + "." + y[1:]
                    
                    if not xZero and j == 0:
                        newX = x
                        xpointAdded = False
                    if not yZero and k == 0:
                        newY = y
                        ypointAdded = False
                    
                    if isValid(newX, xpointAdded) and isValid(newY, ypointAdded):
                        # print(newX, newY)
                        item = "(" + newX + ", " + newY + ")"

                        # print("item ", item)

                        result.add(item)
                     
                    k += 1
                j += 1
        
        return list(result)
                    
            
            
        
            
        
        
        
