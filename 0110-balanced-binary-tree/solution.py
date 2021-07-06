# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution(object):
    def __init__(self):
        self.cache = dict()
        
    def height(self, node):
        if not node:
            return -1
        else:
            if node in self.cache:
                return self.cache[node]
            else:
                left, right = -1, -1
                if node.left in self.cache:
                    left = self.cache[node.left]
                else:
                    left = self.height(node.left)
                    self.cache[node.left] = left
                    
                if node.right in self.cache:
                    right = self.cache[node.right]
                
                else:
                    right = self.height(node.right)
                    self.cache[node.right] = right
                    
                result = max(left, right) + 1
                self.cache[node] = result
                return result
    
    def inOrderTraversal(self, node):
        if not node:
            return True
        queue = deque()
        queue.append(node)
        
        while len(queue) != 0:
            front = queue.popleft()
            if not front:
                continue
            elif abs(self.cache[front.left] - self.cache[front.right]) > 1:
                return False
            else:
                queue.append(front.left)
                queue.append(front.right)
        return True
                
        
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.height(root)
        return self.inOrderTraversal(root)
        
        
        
