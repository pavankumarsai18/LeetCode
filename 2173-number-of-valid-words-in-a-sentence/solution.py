class Solution(object):
    def countValidWords(self, sentence):
        """
        :type sentence: str
        :rtype: int
        """
        result = 0
        for word in sentence.split(" "):
            if len(word) == 0:
                continue
             
            if word[0] == '-' or word[-1] == '-':
                continue
            print(word)
            isValid = True
            numPunct = 0
            numHyphen = 0
            for i in xrange(len(word)):
                if word[i] == '-':
                    numHyphen += 1
                    if numHyphen > 1:
                        isValid = False
                        break
                    cond = word[i-1].isalpha() and word[i+1].isalpha()
                    if cond:
                        continue
                    else:
                        isValid = False
                        break
                    
                elif word[i] == '!' or word[i] == '.' or word[i] == ',':
                    numPunct += 1
                    if numPunct > 1 or i != len(word) - 1:
                        isValid = False
                        break
                elif word[i].isalpha() and word[i].islower():
                    continue
                else:
                    isValid = False
                    break
                        
                        
            if isValid:
                result += 1
        return result
            
