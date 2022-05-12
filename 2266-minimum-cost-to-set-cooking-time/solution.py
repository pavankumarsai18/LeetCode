class Solution(object):
    def minCostSetTime(self, startAt, moveCost, pushCost, targetSeconds):
        """
        :type startAt: int
        :type moveCost: int
        :type pushCost: int
        :type targetSeconds: int
        :rtype: int
        """
        def getCost(num, curDigit):
            result = 0
            for i in range(len(num)):
                if curDigit == num[i]:
                    result += pushCost
                else:
                    curDigit = num[i]
                    result += (moveCost + pushCost)
            return result, curDigit
                
        def cost(time):
            mins, secs = time
            mins = str(int(mins))
                
            curDigit = str(startAt)
            totalCost = 0
            
            if mins != '0':
                minsCost, curDigit = getCost(mins, curDigit)
                secondsCost, curDigit = getCost(secs, curDigit)
                totalCost = minsCost + secondsCost
            else:
                secs = str(int(secs))
                secondsCost, curDigit = getCost(secs, curDigit)
                totalCost = secondsCost
            return totalCost
        
        # 100 -> 1 min 40 s -> 
        # 159 -> 2 min 39 s -> 1 min 99 s
        # 200 -> 60*3 + 20 --> 60*2 + 60
        def allPossibleTimes(targetSeconds):
            mins    = targetSeconds//60
            seconds = str(targetSeconds%60)

            if int(seconds) < 10:
                seconds = "0" + str(seconds)

            newSeconds = str(int(seconds) + 60)

            result = []
            if mins <= 99 and int(seconds) <= 99:
                result.append((str(mins), seconds))
            if int(newSeconds) <= 99 and mins - 1 >= 0:
                result.append((str(mins-1), newSeconds))
        
            return result
                
                
        possibleTimes = allPossibleTimes(targetSeconds)
        # print(possibleTimes)
        minCost = float('inf')
        for time in possibleTimes:
            minCost = min(minCost, cost(time))
        
        return minCost
