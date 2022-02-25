class Solution(object):
    def linearRob(self, nums):
        t1 = 0;
        t2 = 0;

        for i in range(len(nums)): 
            temp = t1;
            current = nums[i];
            t1 = max(current + t2, t1);
            t2 = temp;
        

        return t1;
    
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        return max(self.linearRob(nums[:-1]), self.linearRob(nums[1:]))

