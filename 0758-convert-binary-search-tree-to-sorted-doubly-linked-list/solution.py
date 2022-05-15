"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        
      
        def inorder(node):
            nonlocal firstNode, lastNode
            if not node:
                return
            
            inorder(node.left)
            if lastNode:
                lastNode.right = node
                node.left = lastNode
            else:
                firstNode = node
            
            lastNode = node
            inorder(node.right)
            
        firstNode, lastNode = None, None

        inorder(root)
        
        firstNode.left = lastNode
        lastNode.right = firstNode
        return firstNode
        
        
        
