class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 3:
            return False
        s = 1
        for i in range(2, int(math.ceil(math.sqrt(num)))):
            if num%i == 0:
                s+= i
                s += num/i

        if s == num:
            return True
        return False
