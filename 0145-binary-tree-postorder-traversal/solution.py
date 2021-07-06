# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postArray(self, node, arr):
        if not node:
            return
        if not node.left and not node.right:
            arr.append(node.val)
            return
        else:
            self.postArray(node.left, arr)
            self.postArray(node.right, arr)
            arr.append(node.val)
            return
                
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = list()
        self.postArray(root, result)
        return result
        
