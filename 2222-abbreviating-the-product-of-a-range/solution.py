class Solution(object):
    def abbreviateProduct(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: str
        """
        
        product = 1
        for n in xrange(left, right+1):
            product = product*n
            
        strNum = str(product)
        
        numZeros = 0
        
        i = len(strNum) - 1
        while i >= 0 and strNum[i] == '0':
            i -= 1
            numZeros += 1
        
        strNum = strNum[:len(strNum)-numZeros]

        if len(strNum) > 10:
            result = strNum[:5] + "..." + strNum[-5:]
        else:
            result = strNum
        
        return result + "e" + str(numZeros)
            
        
