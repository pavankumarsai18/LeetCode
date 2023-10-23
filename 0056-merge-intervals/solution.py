class Solution:
    def overlaps(self, cur_interval, next_interval):
        a, b = cur_interval
        c, d = next_interval

        # a c d b
        # a c b d
        
        if a <= c <= b:
            return (True, [a, max(b, d)])
        else:
            return (False, None)


    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        ans = []
        n = len(intervals)
        idx = 0
        while idx < n:
            cur_interval = intervals[idx]
            while idx + 1 < n:
                overlap, merged_int =  self.overlaps(cur_interval, intervals[idx + 1])
                if overlap:
                    cur_interval = merged_int
                    idx += 1
                else:
                    break
            ans.append(cur_interval)
            idx += 1

        return ans
