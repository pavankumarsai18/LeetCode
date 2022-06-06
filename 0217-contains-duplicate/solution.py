class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        numSet = set()
        
        for num in nums:
            if num not in numSet:
                numSet.add(num)
            else:
                return True
            
        return False
