# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#    def get(self, index):
#        """
#        :type index: int
#        :rtype int
#        """

class Solution(object):
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
#         outofBounds = 2147483647
#         lo = 0
#         hi = 10000
#         lastIdx = hi
#         while hi >= lo:
#             mid = (lo) + (hi - lo)//2
#             lastIdx = mid
#             val = reader.get(mid)
#             if val == target:
#                 return mid
            
#             if val == outofBounds:
#                 hi = mid - 1
#             elif val != outofBounds and reader.get(mid + 1) == outofBounds:
#                 lastIdx = mid
#                 break
#             else:
#                 lo = mid + 1
        lo = 0
        hi = target-reader.get(0)
        while hi >= lo:
            mid = lo + (hi - lo)//2
            val = reader.get(mid)
            if val == target:
                return mid
            elif val < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return -1
