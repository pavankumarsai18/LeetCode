# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0
        
        def depth(node):
            nonlocal diameter
            
            if not node:
                return -1
            
            left_depth  = depth(node.left)
            right_depth = depth(node.right)
            
            diameter = max(diameter, left_depth + right_depth + 2)
            
            return max(left_depth, right_depth) + 1
        
        depth(root)
        
        return diameter
