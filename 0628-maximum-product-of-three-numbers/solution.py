class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        # maximize product of two numbers and delete them from the list
        # find the max element in the arr
        nums.sort()
        # xyz
        # yz + zx + xy -- min
        # (z + x + y)*2 < 0
        return max(nums[0]*nums[1]*nums[-1], nums[-1]*nums[-2]*nums[-3])
