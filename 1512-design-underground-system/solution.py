class UndergroundSystem(object):

    def __init__(self):
        self.checkInMap = dict()
        self.stationMap = dict()
        
    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.checkInMap[id] = (stationName, t)       
        

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        item = (self.checkInMap[id][0])+"->"+stationName
        timeTaken =  t - self.checkInMap[id][1]
        if item in self.stationMap:
            newTotalTime = self.stationMap[item][0] + timeTaken
            newCount = self.stationMap[item][1] + 1
            self.stationMap[item] = (newTotalTime, newCount)
        else:
            self.stationMap[item] = (timeTaken, 1)
            
        
    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        item = startStation + "->"+endStation
        totalTime = (self.stationMap[item][0])*1.0
        count = self.stationMap[item][1]
        return totalTime/count


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
