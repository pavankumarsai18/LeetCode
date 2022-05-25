# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        def isLeaf(node):
            return (node and (not node.left) and (not node.right))
        
        if not root:
            return root
        
        if root.left and isLeaf(root.left):
            if isLeaf(root.right):
                temp = root.right
                root.right = root.left
                root.right.right = temp
                root.left = None
            
            elif not root.right:
                root.right = root.left 
                root.left = None
            
        elif not root.left:
            self.flatten(root.right)
            return root
                
            
        firstHalf = self.flatten(root.left)
        secondHalf = self.flatten(root.right)
        if firstHalf != None:
            root.right = firstHalf
            cur = firstHalf
            while cur and cur.right:
                cur = cur.right

            cur.right = secondHalf
            root.left = None
        else:
            root.right = secondHalf
        
        return root
