class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        negative = []
        positive = []
        zeros = 0
        
        for num in nums:
            if num > 0:
                positive.append(num)
            elif num == 0:
                zeros += 1
            else:
                negative.append(num)
        
        result = []
        encounteredTuples = set()
        
        negativeSet = set(negative)
        positiveSet = set(positive)
        
        if zeros >= 3:
            encounteredTuples.add((0,0,0))
        
        # 2 positive 1 negative
        for p1, p2 in itertools.combinations(positive, 2):
            if -(p1 + p2) in negativeSet:
                item = tuple(sorted([p1, p2, -(p1+p2)]))
                encounteredTuples.add(item)
        
        # 2 negative 1 positive
        for n1, n2 in itertools.combinations(negative, 2):
            if -(n1 + n2) in positiveSet:
                item = tuple(sorted([n1, n2, -(n1+n2)]))
                encounteredTuples.add(item)
        
        # 1 positive 1 negative 1 zero
        if zeros > 0:
            for p in positive:
                if -p in negativeSet:
                    item = tuple([-p, 0, p])
                    encounteredTuples.add(item)

        return [list(item) for item in encounteredTuples]
