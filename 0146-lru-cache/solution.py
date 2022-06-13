from collections import defaultdict

class LinkedNode:
    def __init__(self, key=None, val=None):
        self.key = key
        self.value = val
        self.next, self.prev = None, None
    
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache    = defaultdict(LinkedNode)
        
        self.head, self.tail = LinkedNode(), LinkedNode()
        self.head.next, self.tail.prev = self.tail, self.head
    
    def printList(self):
        result = []
        cur = self.head
        while cur:
            result.append(str((cur.key,cur.value)))
            cur = cur.next
        print("".join(result))
        return
        
    def detach(self, node):
        prevNode, nextNode = node.prev, node.next
        
        node.prev, node.next = None, None
        
        prevNode.next = nextNode
        nextNode.prev = prevNode
        return
    
    def addHead(self, node):
        headNext = self.head.next
        node.prev = self.head
        node.next = headNext
        
        headNext.prev = node
        self.head.next = node
    
    def moveHead(self, node):
        self.detach(node)
        self.addHead(node)

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.moveHead(self.cache[key])
        return self.cache[key].value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].value = value
            self.moveHead(self.cache[key])
            return
        
        if len(self.cache) == self.capacity:
            LRUKey = self.tail.prev.key
            self.detach(self.cache[LRUKey])
            del self.cache[LRUKey]
            
        newNode = LinkedNode(key, value)
        self.cache[key] = newNode
        self.addHead(newNode)



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
