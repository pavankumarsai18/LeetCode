class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        char_count = dict()
        
        for c in s:
            if c in char_count:
                char_count[c] += 1
            else:
                char_count[c] = 1
        
        numEven = 0
        numOdd = 0
        
        for key in char_count:
            if char_count[key]%2 == 0:
                numEven += 1
            else:
                numOdd += 1
        
        if len(s)%2 == 1:
            return numOdd == 1
        
        return numOdd == 0
            
