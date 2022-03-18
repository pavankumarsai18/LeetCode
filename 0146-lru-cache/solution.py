class Node():
    def __init__(self, key=-1, value=-1):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
    def __repr__(self):
        return str(self.key) + ":"+ str(self.value)
class LRUCache(object):
    
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cache = dict()
        self.head = Node(-1,-1)
        self.tail = Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def addBeforeNode(self, new_node, prev_node):
        # print("In addBefore")
        # print("new_node",new_node,"prev", prev_node)
        prev_node.prev, new_node.prev = new_node, prev_node.prev
        (new_node.prev).next, new_node.next = new_node, prev_node
    
    def removeNode(self, n):
        prevNode = n.prev
        nextNode = n.next
        prevNode.next, nextNode.prev = nextNode, prevNode
        return n
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            curNode = self.cache[key]
            self.removeNode(curNode)
            self.addBeforeNode(curNode, self.tail)
            return curNode.value
            
        return -1
            
        
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        newNode = Node(key, value)
        if key in self.cache:
            node = self.cache[key]
            self.removeNode(node)
        else:
            if len(self.cache) == self.capacity:
                n = self.removeNode(self.head.next)
                del self.cache[n.key]

        self.cache[key] = newNode
        self.addBeforeNode(newNode, self.tail)

                
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
