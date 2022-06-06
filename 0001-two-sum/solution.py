class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        numCount = defaultdict(list)
        
        for i in range(len(nums)):
            numCount[nums[i]].append(i)
            
        
        result = []
        for num in numCount.keys():
            index1 = numCount[num].pop()
            
            second_num = target - num
            
            if len(numCount[second_num]) > 0:
                index2 = numCount[second_num].pop()
                result.append(index1)
                result.append(index2)
                return result
            
            numCount[num].append(index1)
            
        return result
                
