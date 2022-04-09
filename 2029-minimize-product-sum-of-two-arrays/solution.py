class Solution(object):
    def minProductSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        nums1Count = [0 for _ in range(101)]
        nums2Count = [0 for _ in range(101)]
        
        for i in xrange(len(nums1)):
            nums1Count[nums1[i]] += 1
            nums2Count[nums2[i]] += 1
        
        p1 = 1
        p2 = 100
        result = 0
        while p1 <= 100 and p2 > 0:
            while p1 <= 100 and nums1Count[p1] == 0:
                p1 += 1
            while p2 > 0 and nums2Count[p2] == 0:
                p2 -= 1
            if p1 == 101 or p2 == 0:
                break
            minCount = min(nums1Count[p1], nums2Count[p2])
            result += minCount*p1*p2
            nums1Count[p1] -= minCount
            nums2Count[p2] -= minCount
            
        return result
        
