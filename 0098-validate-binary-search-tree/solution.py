# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def listTree(self, root, l):
        if root.left:
            self.listTree(root.left, l)
        l.append(root.val)
        if root.right:
            self.listTree(root.right, l)
        return    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        
        l = []
        self.listTree(root,l)
        
        for i in xrange(len(l)-1):
            if l[i] >= l[i+1]:
                return False
        
        return True
        
