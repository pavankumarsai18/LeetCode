class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 1:
            total = 0
            if nums[0] == target:
                total += 1
            elif nums[0]*-1 == target:
                total += 1
            return total
        
        def findWays(nums, index, target, cache):
            if (index, target) in cache:
                return cache[(index, target)]
            
            if index == 0:
                total = 0
                if nums[0] == target:
                    total += 1
                if nums[0]*-1 == target:
                    total += 1
                return total

            # use positive '+'
            totalWays = findWays(nums,index-1, target - nums[index], cache)
            # use negative
            totalWays += findWays(nums,index-1, target + nums[index], cache)
            
            cache[(index, target)] = totalWays
            return totalWays
        
        cache = dict()
        return findWays(nums, len(nums)-1,target, cache)
