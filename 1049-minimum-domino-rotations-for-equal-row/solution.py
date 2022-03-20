class Solution(object):
    def minDominoRotations(self, tops, bottoms):
        """
        :type tops: List[int]
        :type bottoms: List[int]
        :rtype: int
        """
        n = len(tops)
        topCounter = dict()
        bottomCounter = dict()
        
        for i in xrange(len(tops)):
            top = tops[i]
            if top not in topCounter:
                topCounter[top] = set()
            topCounter[top].add(i)
        
        for i in xrange(len(bottoms)):
            bottom = bottoms[i]
            if bottom not in bottomCounter:
                bottomCounter[bottom] = set()
            bottomCounter[bottom].add(i)
        
        
        minRotations = float('inf')
        possible = False
        for num in topCounter:
            if num in bottomCounter:
                A = topCounter[num]
                B = bottomCounter[num]
                unionIndices = A.union(B)
                if len(unionIndices) == n:
                    possible = True
                    numRotations = min(len(A - B), len(B - A))
                    minRotations = min(minRotations, numRotations)
                
        if possible == False:
            return -1
        return minRotations
                    
