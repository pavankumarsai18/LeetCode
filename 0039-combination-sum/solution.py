class Solution(object):
    def stringify(self, Map):
        result = ""
        counter = 0
        for key in Map:
            result += str(key)+":"+str(Map[key])
            if counter != len(Map)-1:
                result += ";"
            counter += 1
        return result
            
    def findSum(self, candidates, target, memo):
        if target in memo:
            return memo[target]
        if target <= 0:
            memo[target] = [[]]
            return [[]]
        
        allCombs = []
        for candidate in candidates:
            if candidate == target:
                allCombs.append([candidate])
        
        
        for candidate in candidates:
            if target - candidate <= 0:
                continue
            excludedSum = self.combinationSum(candidates, target - candidate)
            for comb in excludedSum:
                if len(comb) > 0:
                    temp = copy.deepcopy(comb)
                    temp.append(candidate)
                    allCombs.append(temp)

        uniqueComb = set()
        result = []
        for comb in allCombs:
            d = dict(enumerate(sorted(comb)))
            hashValue = self.stringify(d)
            if hashValue not in uniqueComb:
                uniqueComb.add(hashValue)
                result.append(comb)
        
        memo[target] = result
        return result
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        memo = dict()
        return self.findSum(candidates, target, memo)
        
