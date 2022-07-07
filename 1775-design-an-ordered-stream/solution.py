class OrderedStream:

    def __init__(self, n: int):
        self.buffer = [None]*(n+1)
        self.ptr = 1
        
    def insert(self, idKey: int, value: str) -> List[str]:
        self.buffer[idKey] = value
        ans = []
        while self.ptr < len(self.buffer) and self.buffer[self.ptr]:
            ans.append(self.buffer[self.ptr])
            self.ptr += 1
        return ans
            
        


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
