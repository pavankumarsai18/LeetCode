class Solution(object):
    def arraysIntersection(self, arr1, arr2, arr3):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type arr3: List[int]
        :rtype: List[int]
        """
        s1 = set(arr1)
        s1 = s1.intersection(set(arr2))
        s1 = s1.intersection(set(arr3))
        
        result = []
        for i in xrange(len(arr1)):
            if arr1[i] in s1:
                result.append(arr1[i])
        return result
