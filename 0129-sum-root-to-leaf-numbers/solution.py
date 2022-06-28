# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        root_to_leaf = cur_num = 0
        
        while root:
            
            if root.left:
                parent = root.left
                steps       = 1
                
                while parent.right and parent.right is not root:
                    parent = parent.right
                    steps  += 1
                
                if parent.right is None:
                    cur_num = cur_num*10 + root.val
                    parent.right = root
                    root         = root.left
                    
                else:
                    if parent.left is None:
                        root_to_leaf += cur_num
                    cur_num = cur_num//pow(10, steps)
                    parent.right = None
                    root = root.right
            else:
                cur_num = cur_num*10 + root.val
                if root.right is None:
                    root_to_leaf += cur_num
                
                root = root.right
        return root_to_leaf
                
        
