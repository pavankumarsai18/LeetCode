class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return 2*(sum(set(nums))) - sum(nums)
#         dup = {}
#         for i in range(len(nums)):
#             if nums[i] in dup:
#                 x = dup[nums[i]]
#                 dup[nums[i]] = x + 1
#             else:
#                 dup[nums[i]] = 1

#         for key in dup:
#             if dup[key] == 1:
#                 return key
                
            
        
