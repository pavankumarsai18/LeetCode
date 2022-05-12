class Solution(object):
    def sortJumbled(self, mapping, nums):
        """
        :type mapping: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        
        def mapped_num(num):
            strNum = str(num)
            result = ""
            for digit in strNum:
                result += str(mapping[int(digit)])
            return int(result)
        
        newMap = {num: mapped_num(num) for num in nums}
    
        nums.sort(key=lambda x: newMap[x])
        return nums
