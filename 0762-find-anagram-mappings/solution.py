class Solution(object):
    def anagramMappings(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        numIndex = dict()
        
        for num in nums1:
            numIndex[num] = list()
            
        for index,num in enumerate(nums2):
            numIndex[num].append(index)
        
        result = []
        
        for num in nums1:
            result.append(numIndex[num].pop())
        return result
