# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        
        closest = root.val
        curNode = root
        while curNode:
            closest = min(closest, curNode.val, key=lambda x: abs(x - target))
            curNode = curNode.left if target < curNode.val else curNode.right
        return closest
