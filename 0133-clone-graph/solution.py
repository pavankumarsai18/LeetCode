"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if node == None:
            return None
        
        visited = set()        
        q = deque()
        q.append(node)
        
        cloneMap = dict()
        while len(q):
            n = q.popleft()
            if n not in visited:
                visited.add(n)

                cloneNode = Node(n.val)
                cloneMap[n] = cloneNode
                if n.neighbors != None:
                    for neighbor in n.neighbors:
                        q.append(neighbor)
                
        q = deque()
        q.append(node)
        result = cloneMap[node]
        
        for n in cloneMap:
            neighbors = None
            if n.neighbors:
                cloneMap[n].neighbors = [cloneMap[m] for m in n.neighbors]
        
        return result
                

