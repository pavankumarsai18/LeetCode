# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getParents(self, root, startVal, destVal):
        if not root:
            return
        if root.val == startVal:
            self.start = root
        elif root.val == destVal:
            self.dest = root
            
        if root.left:
            self.parent[root.left]  = root
        if root.right:
            self.parent[root.right] = root
        
        self.getParents(root.left, startVal, destVal)
        self.getParents(root.right, startVal, destVal)
    
    
    def getDirections(self, root, startValue, destValue):
        """
        :type root: Optional[TreeNode]
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        
        def bfs(start):
            Q = collections.deque()
            Q.append(start)
            
            
            while Q:
                node = Q.popleft()
                if node.val == destValue:
                    return
                
                parentNode = self.parent[node]
                
                if node.left and node.left not in self.route:
                    Q.append(node.left)
                    self.route[node.left] = (node, "L")
                if node.right and node.right not in self.route:
                    Q.append(node.right)
                    self.route[node.right] = (node, "R")
                if parentNode and parentNode not in self.route:
                    Q.append(parentNode)
                    self.route[parentNode] = (node, "U")
            
            return
        
        self.start, self.dest = None, None
        self.parent, self.route = {root:None}, {}
        self.getParents(root, startValue, destValue)
        
        bfs(self.start)
        
        result = []
        cur = self.dest
        while cur != self.start:
            cur, move = self.route[cur]
            result.append(move)
        
        return "".join(result[::-1])
        
        
        
        
        
