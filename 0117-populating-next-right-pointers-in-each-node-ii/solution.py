"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        Q = list()
        Q.append(root)
        
        while len(Q) > 0:
            newQ = list()
            
            counter = 0
            while counter < len(Q):
                node = Q[counter]
                if node != None and counter + 1 < len(Q):
                    node.next = Q[counter+1]
                if node:
                    if node.left:
                        newQ.append(node.left)
                    if node.right:
                        newQ.append(node.right)
                counter += 1
                
            Q = newQ
            
        return root
