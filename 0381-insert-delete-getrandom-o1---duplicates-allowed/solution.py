class RandomizedCollection:
    def __init__(self):
        self.lst = []
        self.idx = defaultdict(set)
                
        
    def insert(self, val: int) -> bool:
        self.idx[val].add(len(self.lst))
        self.lst.append(val)
        
        return len(self.idx[val]) == 1
        
    def remove(self, val: int) -> bool:
        if not self.idx[val]: 
            return False
        remove, last = self.idx[val].pop(), self.lst[-1]
        
        self.lst[remove] = last
        
        self.idx[last].add(remove)
        self.idx[last].discard(len(self.lst)-1)
        
        self.lst.pop()
        return True
    
    def getRandom(self) -> int:

        return choice(self.lst)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
