class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return 1

        setNums        = set(nums)
        
        longestSequence = 0
        for num in setNums:     
            if num-1 not in setNums:
                cur = num
                lengthSequence  = 1
                while cur+1 in setNums:
                    cur = cur + 1
                    lengthSequence += 1                
                longestSequence = max(lengthSequence, longestSequence)
        
        return longestSequence
                
                    
                
        

