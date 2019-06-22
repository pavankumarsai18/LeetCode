class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_num = {}
        
        for i in range(len(nums)):
            if target - nums[i] in  index_num:
                return [index_num[target - nums[i]], i]
            index_num[nums[i]] = i
        
                
