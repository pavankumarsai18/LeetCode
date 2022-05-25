class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """        
        length = 1 << n
        
        grayCodes = []
        for i in range(length):
            grayCodes.append((i^(i>>1)))
        
        return grayCodes
