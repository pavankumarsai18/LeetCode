class SnapshotArray:

    def __init__(self, length: int):
        self.arr = [[[0,0]] for _ in range(length)]
        self.snapID = 0

    def set(self, index: int, val: int) -> None:
        if len(self.arr[index]) > self.snapID:
            self.arr[index][self.snapID][1] = val
        else:
            self.arr[index].append([self.snapID, val])

    def snap(self) -> int:
        ans = self.snapID
        self.snapID += 1
        return ans
        

    def get(self, index: int, snap_id: int) -> int:
        lo = 0
        hi = len(self.arr[index]) - 1
        
        while lo < hi:
            mid = lo + (hi - lo + 1)//2
            if self.arr[index][mid][0] > snap_id:
                hi = mid - 1
            else:
                lo = mid
        return self.arr[index][lo][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
