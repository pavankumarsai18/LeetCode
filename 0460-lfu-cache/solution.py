class Node(object):
    def __init__(self, val, count):
        self.value = val
        self.count = count


class LFUCache:

    def __init__(self, capacity: int):
        self.capacity  = capacity
        self.nodeKeys  = defaultdict(Node)
        self.nodeCount = defaultdict(OrderedDict)
        self.minCount  = None

    def get(self, key: int) -> int:
        if self.capacity == 0 or key not in self.nodeKeys:
            return -1
        
        node = self.nodeKeys[key]
        del self.nodeCount[node.count][key]
        
        node.count += 1
        self.nodeCount[node.count][key] = node
        
        if len(self.nodeCount[self.minCount]) == 0:
            del self.nodeCount[self.minCount]
            self.minCount += 1
        
        return node.value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.nodeKeys:
            self.nodeKeys[key].value = value
            self.get(key)
            return
        
        if len(self.nodeKeys) == self.capacity:
            lfuKey, lfuNode = self.nodeCount[self.minCount].popitem(last=False)
            del self.nodeKeys[lfuKey]
        
        newNode = Node(value, 1)
        
        self.nodeKeys[key]     = newNode
        self.nodeCount[1][key] = newNode
        
        self.minCount = 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
