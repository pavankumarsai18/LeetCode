class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        
        envelopes.sort(key=lambda x: (x[0], -x[1]))
    
        def lis(nums):
            dp = []
            for i in range(len(envelopes)):
                idx = bisect_left(dp, nums[i])
                
                if idx == len(dp):
                    dp.append(nums[i])
                else:
                    dp[idx] = nums[i]
            return len(dp)
        
        return lis([dim[1] for dim in envelopes])
