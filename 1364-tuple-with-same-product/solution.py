class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        num_set = set(nums)
        nums = sorted(nums)
        mult_count = dict()

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                mult = nums[i]*nums[j]
                if mult not in mult_count:
                    mult_count[mult] = set()
                mult_count[mult].add((i, j))
        
        ans = 0
        for mult, values in mult_count.items():
            if len(values) >= 2:
                ans += len(values) * (len(values) - 1)*4
        return ans

        

        




        
        
