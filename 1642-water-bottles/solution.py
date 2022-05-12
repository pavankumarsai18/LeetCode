class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """

        sum=numBottles
        while (numBottles/numExchange>0):
        
            a= numBottles//numExchange
            b= numBottles%numExchange
            sum +=a
            numBottles=a+b
        
        return sum;
