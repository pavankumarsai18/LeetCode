class Solution(object):
    def stringify(self, nums):
        result = ""
        for num in nums:
            result += str(num) + ","
        return result
    
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        def backtrack(comb, counter):
            if len(comb) == len(nums):
                result.append(list(comb))
                return
            
            for num in counter:
                if counter[num] > 0:
                    comb.append(num)
                    counter[num] -= 1
                    
                    backtrack(comb, counter)
                    
                    comb.pop()
                    counter[num] += 1
                    
        backtrack([], Counter(nums))
        
        return result
                    
                    
                                

        
        
        
