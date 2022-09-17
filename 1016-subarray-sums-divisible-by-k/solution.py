class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        sum_ = 0
        numCount = defaultdict(int)
        numCount[0] = 1
        
        for num in nums:
            sum_ += num
            remainder = (sum_)%k
            
            ans += numCount[remainder]
            
            numCount[remainder] += 1
            
        return ans
        
        
        
        
        
        
            

