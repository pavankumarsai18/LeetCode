class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        numCount = defaultdict(int)
        
        for num in nums:
            numCount[num] += 1
        
        nums.sort(key=lambda x: (numCount[x], -x))
        
        return nums
