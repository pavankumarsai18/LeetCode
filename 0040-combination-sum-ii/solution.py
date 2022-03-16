class Solution(object):
    def stringify(self, nums):
        result = ""
        for i in xrange(len(nums)):
            result += str(nums[i])
            if i != len(nums) -1:
                result += ","
        return result
    
    def findCombinations(self, numCount, target, memo):
        if target <= 0:
            return [[]]
        
        nums = []
        Sum = 0
        for key in numCount:
            if numCount[key] > 0:
                for i in xrange(numCount[key]):
                    nums.append(key)
                    Sum += key
        if Sum < target:
            return []
        elif Sum == target:
            return [nums]
        
        if (target, self.stringify(sorted(nums))) in memo:
            return memo[(target, self.stringify(sorted(nums)))]
        
        result = []
        for num in nums:
            if num == target:
                result.append([num])
        
        for num in nums:
            if numCount[num] > 0:
                newTarget = target - num
                numCount[num] -= 1
                excludedCombs = self.findCombinations(numCount, newTarget, memo)
                
                for comb in excludedCombs:
                    if len(comb) > 0:
                        copyComb = copy.deepcopy(comb)
                        copyComb.append(num)
                        result.append(copyComb)
                numCount[num] += 1
        
        uniqueComb = set()
        newResult = []
        for comb in result:
            hashVal = self.stringify(sorted(comb))
            if hashVal not in uniqueComb:
                uniqueComb.add(hashVal)
                newResult.append(comb)
        
        result = newResult
        memo[(target, self.stringify(sorted(nums)))] = result

        return result
    
            
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        numCount = dict()
        for c in candidates:
            if c in numCount:
                numCount[c] += 1
            else:
                numCount[c] = 1
        memo = dict()
        result = self.findCombinations(numCount, target, memo)
        memo = dict()
        return result
        
