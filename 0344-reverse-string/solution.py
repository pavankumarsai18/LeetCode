class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        
        for i in xrange(len(s)//2):
            s[i], s[len(s)-1-i] = s[len(s)-1-i],s[i]
            
