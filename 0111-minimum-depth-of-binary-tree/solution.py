# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.cache = dict()
        
    def depth(self, node):
        if not node:
            return 0
        if (not node.left) and (not node.right):
            return 1

        left, right = 0,0
        if node.left in self.cache:
            left = self.cache[node.left]
        else:
            left = self.depth(node.left)
            self.cache[node.left] = left

        if node.right in self.cache:
            right = self.cache[node.right]
        else:
            right = self.depth(node.right)
            self.cache[node.right] = right
            
        if not node.left and node.right:
            left = right
            
        if not node.right and node.left:
            right = left
            
        return min(left, right) + 1
        
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.depth(root)
        
        
