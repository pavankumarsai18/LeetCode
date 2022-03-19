class Solution(object):
    
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        
        intervals = sorted(intervals, key=lambda x: x[0])
        
        result = []
        for interval in intervals:
            if len(result) == 0 or result[-1][1] < interval[0]:
                result.append(interval)
            else:
                result[-1][1] = max(result[-1][1], interval[1])
        return result
