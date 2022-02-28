class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lastPos = len(nums) - 1;
        for i in xrange(len(nums) - 1, -1, -1):
            if (i + nums[i] >= lastPos):
                lastPos = i;
            
        
        return lastPos == 0;
