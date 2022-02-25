class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        nums1 = [int(num) for num in version1.split('.')]
        nums2 = [int(num) for num in version2.split('.')]
        
        for i in xrange(max(len(nums1), len(nums2))):
            if i < min(len(nums1), len(nums2)):
                if (nums1[i] - nums2[i]) != 0:
                    return 1 if nums1[i] > nums2[i] else -1
                nums1[i] = nums2[i] = 0
                
        swapped = False
        if len(nums1) < len(nums2):
            swapped = True
            nums1, nums2 = nums2, nums1

        for i in xrange(len(nums2),len(nums1)):
            if nums1[i] != 0:
                if swapped:
                    return -1 if nums1[i] else 1
                else:
                    return 1 if nums1[i] else -1
        
        return 0


                
