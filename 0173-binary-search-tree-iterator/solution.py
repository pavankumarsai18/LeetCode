# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.curPtr = root
        
        self.min = self.curPtr
        self.max = self.curPtr
        self.parent = dict()
        
        self.parent[root] = None
        self.preOrder(root)
        
        
        while self.min.left:
            self.min = self.min.left 
        while self.max.right:
            self.max = self.max.right
    
        self.curPtr = None
    
    def preOrder(self, root):
        if root.left:
            self.parent[root.left] = root
            self.preOrder(root.left)
        if root.right:
            self.parent[root.right] = root
            self.preOrder(root.right)
        
        
    def next(self):
        """
        :rtype: int
        """
        if self.curPtr is None:
            self.curPtr = self.min
            return self.curPtr.val 
        
        result = self.curPtr

        if self.hasNext():
            if result.right:
                result = result.right
                while result.left:
                    result = result.left
            else:
                while self.parent[result]:
                    if self.parent[result].left == result:
                        result = self.parent[result]
                        break
                    else:
                        result = self.parent[result]
        
        self.curPtr = result
        return self.curPtr.val
            
            
            
        
    def hasNext(self):
        """
        :rtype: bool
        """
        if self.curPtr != self.max:
            return True
        return False


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
