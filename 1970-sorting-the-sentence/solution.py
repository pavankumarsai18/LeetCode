class Solution(object):
    def sortSentence(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        correctOrder = ["" for _ in range(len(words))]

        result = ""
        for word in words:
            word, index = word[:-1], int(word[-1])
            correctOrder[index-1] = word
        
        for i in range(len(correctOrder)):
            result += correctOrder[i]
            if i != len(correctOrder)-1:
                 result += " "
            
        return result
            
