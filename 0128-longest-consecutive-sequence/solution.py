class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        setNums = set(nums)
        longestSequence = 0
        
        for num in nums:
            if num-1 not in setNums:
                cur = num
                length = 1
                while cur + 1 in setNums:
                    length += 1
                    cur += 1

                longestSequence = max(longestSequence, length)
        return longestSequence
