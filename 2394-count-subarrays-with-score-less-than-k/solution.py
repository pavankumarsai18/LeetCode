class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        windowSum = 0
        numSubArray = 0
        
        left      = 0
        for right, num in enumerate(nums):
            windowSum += num
            while left <= right and (windowSum)*(right-left+1) >= k:
                windowSum -= nums[left]
                left += 1

            length = right-left+1
            numSubArray += length

                        
        return numSubArray
        
