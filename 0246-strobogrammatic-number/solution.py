class Solution(object):
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        
        S = {6:9,8:8,0:0,1:1,9:6}
        
        for i in xrange(len(num)):
            n = int(num[i])
            if n != 6 and n != 9 and n != 8 and n != 1 and n != 0:
                return False
        
        reversedNum = ""
        for i in xrange(len(num) - 1, -1, -1):
            reversedNum += str(S[int(num[i])])
        return reversedNum == num
