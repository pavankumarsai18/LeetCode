"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution(object):
    def lowestCommonAncestor(self, p, q):
        """
        :type node: Node
        :rtype: Node
        """
        
        pParents = []
        qParents = []
        
        cur = p
        while cur:
            pParents.append(cur)
            cur = cur.parent
            
        cur = q
        while cur:
            qParents.append(cur)
            cur = cur.parent
        
        
        i = len(pParents) - 1
        j = len(qParents) - 1
        
        while pParents[i] == qParents[j]:
            i -= 1
            j -= 1
            
        return pParents[i+1]
