class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
 
        if len(nums) == 1:
            return [nums]
        elif len(nums) == 2:
            return [nums, [nums[1], nums[0]]]
        
        result = set()
        
        for index in xrange(len(nums)):
            chosenNumber = nums[index]
            subArray = [nums[i] for i in xrange(len(nums)) if i != index]
            subArrayPermutations = self.permute(subArray)
            for array in subArrayPermutations:
                for i in xrange(len(array)):
                    c = copy.deepcopy(array)
                    c.insert(i, chosenNumber)
                    result.add(tuple(c))
                    
        result = [list(arr) for arr in result]
        return result
