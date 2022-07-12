class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        
        seen   = defaultdict(int)
        for i in range(len(nums)):
            nums[i] %= k
        
        rollingSum = nums[0]
        seen[nums[0]] = 0
        for i in range(1, len(nums)):
            rollingSum += nums[i]
            rollingSum %= k
            
            if rollingSum == 0:
                return True
            if rollingSum in seen and i - seen[rollingSum%k] >= 2:
                return True
            
            if rollingSum not in seen:
                seen[rollingSum] = i
        return False
