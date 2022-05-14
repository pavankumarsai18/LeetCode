# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        parentMap = dict()
        parentMap[root] = None
        def preOrderTraversal(node):
            if node == None:
                return
            if node.left:
                parentMap[node.left] = node
            if node.right:
                parentMap[node.right] = node
            preOrderTraversal(node.left)
            preOrderTraversal(node.right)
        
        preOrderTraversal(root)
        
        pPath = []
        cur = p
        while cur:
            pPath.append(cur)
            cur = parentMap[cur]
        qPath = []
        cur = q
        while cur:
            qPath.append(cur)
            cur = parentMap[cur]
        
        i, j = len(pPath) - 1, len(qPath) - 1
        
        while pPath[i].val == qPath[j].val:
            i -= 1
            j -= 1
        
        return pPath[i+1]
