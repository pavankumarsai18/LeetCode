class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [[], nums]
        
        
        result = self.subsets(nums[:-1])
        chosenNumber = nums[-1]
        l = len(result)
        for i in xrange(l):
            item = result[i]
            newItem = copy.deepcopy(item)
            newItem.append(chosenNumber)
            result.append(newItem)

        return result
