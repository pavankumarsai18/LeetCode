class Solution(object):
    def mostWordsFound(self, sentences):
        """
        :type sentences: List[str]
        :rtype: int
        """
        result = 0
        
        for sentence in sentences:
            result = max(result, len(sentence.split(" ")))
        return result
            
