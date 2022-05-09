class Solution(object):
    def arrangeWords(self, text):
        """
        :type text: str
        :rtype: str
        """
        
        words = text.split(' ')
        
        words = [[words[i].lower(), i] for i in xrange(len(words))]
        
        def compare(x, y):
            if len(x[0]) == len(y[0]):
                if x[1] < y[1]:
                    return -1
                return 1
            
            elif len(x[0]) < len(y[0]):
                return -1
            return 1
        
        words = sorted(words, key=functools.cmp_to_key(compare))
    
        # print(words)
    
        result = ""
        for i in xrange(len(words)):
            if i == 0:
                result += words[i][0].capitalize()
            else:
                result += " " + words[i][0]
            
                
        return result
