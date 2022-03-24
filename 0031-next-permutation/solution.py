class Solution(object):
    def isSorted(self, nums):
        for i in xrange(len(nums) - 1):
            if nums[i + 1] < nums[i]:
                return False
        return True
    
    def isReverseSorted(self, nums):
        for i in xrange(len(nums) - 1):
            if nums[i + 1] > nums[i]:
                return False
        return True
    
    def reverse(self, nums, index):
        i = index
        j = len(nums) - 1
        
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
            
            
    def nextPermutation(self, nums):
        
        if self.isReverseSorted(nums):
            return nums.reverse()

        index = 0
        swapIndex = index
        for i in xrange(len(nums)-2, -1, -1):
            if nums[i+1] > nums[i]:
                index = i
                break
        if index >= 0:
            for i in xrange(len(nums) - 1,index,-1):
                if nums[i] > nums[index]:
                    swapIndex = i
                    break
        
        nums[index], nums[swapIndex] = nums[swapIndex], nums[index]
        self.reverse(nums, index+1)

        return nums
