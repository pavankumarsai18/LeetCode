class Solution:        
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        total    = sum(nums)
    
        if total%k != 0:
            return False
        nums.sort()
        
        bitMask  = ['0']*n    
        target   = total//k
        cache    = defaultdict(bool)
        
        def backtrack(index:int, curSum: int, count: int)->bool:
            bitMaskStr = ''.join(bitMask)
            
            if count == k - 1:
                return True
            
            if curSum > target:
                return False
            
            if bitMaskStr in cache:
                return cache[bitMaskStr]
            
            if curSum == target:
                cache[bitMaskStr] = backtrack(0, 0, count+1)
                return cache[bitMaskStr]
            
            for j in range(index, n):
                if bitMask[j] == '0':
                    bitMask[j] = '1'
                    
                    if backtrack(j+1, curSum + nums[j], count):
                        return True
                    
                    bitMask[j] = '0'
            
            cache[bitMaskStr] = False
            return cache[bitMaskStr]
        return backtrack(0, 0, 0)
        
        
