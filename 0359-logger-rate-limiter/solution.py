class Logger(object):

    def __init__(self):
        self.latestTime = dict()

    def shouldPrintMessage(self, timestamp, message):
        """
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        if message not in self.latestTime:
            self.latestTime[message] = timestamp
            return True
        
        if timestamp - self.latestTime[message] >= 10:
            self.latestTime[message] = timestamp
            return True
        return False




# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
