class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2, similarPairs):
        """
        :type sentence1: List[str]
        :type sentence2: List[str]
        :type similarPairs: List[List[str]]
        :rtype: bool
        """
        
        if len(sentence1) != len(sentence2):
            return False
        
        similarMap = dict()
        for i in xrange(len(similarPairs)):
            if similarPairs[i][0] not in similarMap:
                similarMap[similarPairs[i][0]] = set()
            similarMap[similarPairs[i][0]].add(similarPairs[i][1])

        isSame = True
        for i in xrange(len(sentence1)):
            if sentence1[i] != sentence2[i]:
                isSame = False
                break
        if isSame:
            return True
        # print(similarMap)
        
        # n = min(len(sentence1), len(similarMap))
        for i in xrange(len(sentence1)):
            if sentence1[i] == sentence2[i]:
                continue
                
            isSimilar = False
            if sentence1[i] in similarMap:
                # print("val", sentence2[i],sentence1[i], similarMap[sentence1[i]])
                if sentence2[i] in similarMap[sentence1[i]]:
                    isSimilar = True
                    
            if not isSimilar and sentence2[i] in similarMap:
                # print("val", sentence1[i],sentence2[i], similarMap[sentence2[i]])
                if sentence1[i] in similarMap[sentence2[i]]:
                    isSimilar = True
            
            # print(isSimilar)
            
            if not isSimilar:
                return False
        
        return True
