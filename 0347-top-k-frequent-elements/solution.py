class Solution(object):
    class freqNum(object):
        def __init__(self, num, freq):
            self.num = num
            self.freq = freq
        def __lt__(self, other):
            return lt(self.freq, other.freq)
        
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        numCount = collections.Counter(nums)
        q = []
        for key,val in numCount.items():
            heapq.heappush(q, self.freqNum(key, val))
            if len(q) > k:
                heapq.heappop(q)
        
        return [x.num for x in q]
