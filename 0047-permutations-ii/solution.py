class Solution(object):
    def permute(self, nums):
        if len(nums) == 0:
            return [[]]
        
        if len(nums) == 1:
            return [nums]
        if len(nums) == 2:
            a, b = nums[0], nums[1]
            return [[a,b],[b,a]]
        
        result = set()
        num = nums[0]
        items = self.permute(nums[1:])
        for j in xrange(len(items)):
            for i in xrange(len(nums)):
                temp = list(copy.deepcopy(items[j]))
                temp.insert(i, num)
                result.add(tuple(temp))
        return list(result)
        
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        numCount = dict()
        for num in nums:
            if num in numCount:
                numCount[num] += 1
            else:
                numCount[num] = 1
        
        dupNums = []
        for num in numCount:
            for i in range(numCount[num]):
                dupNums.append(str(num) + ":"+str(i))
                
        result = set()
        dupPermutations = self.permute(dupNums)
        for item in dupPermutations:
            permutation = []
            for s in item:
                permutation.append(int(s[:s.find(':')]))
            result.add(tuple(permutation))
        
        result = [list(item) for item in result]
        
        return result
