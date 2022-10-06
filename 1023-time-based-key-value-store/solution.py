class TimeMap:

    def __init__(self):
        self.timeMap  = dict()
        self.valueMap = dict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.timeMap:
            self.timeMap[key]  = []
            self.valueMap[key] = []
        
        self.timeMap[key].append(timestamp)
        self.valueMap[key].append(value)
            
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.timeMap:
            return ""
        
        lo, hi = 0, len(self.timeMap[key]) 
        if self.timeMap[key][lo] > timestamp:
            return ""
        
        ans = 0
        while lo < hi:
            mid = (lo + hi)//2
            if self.timeMap[key][mid] > timestamp:
                hi = mid - 1
            else:
                ans = mid
                lo = mid + 1
                
        # print(f"index {ans} key={key} timestamp={timestamp}")
        # print(f"timeMap={self.timeMap} valueMap={self.valueMap}")
        # print(f"ans ={self.valueMap[key][ans]}")
        return self.valueMap[key][ans]
        
        
# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
