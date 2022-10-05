# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            newRoot = TreeNode(val, root, None)
            return newRoot
        
        
        Q = collections.deque()
        Q.append(root)
                
        for curDepth in range(1, depth-1):
            newQ = collections.deque()            
            while Q:
                node = Q.popleft()
                if node.left:
                    newQ.append(node.left)
                if node.right:
                    newQ.append(node.right)
            
            Q = newQ
        
        for node in Q:
            left  = node.left
            right = node.right 
            node.left = TreeNode(val, left, None)
            node.right = TreeNode(val,None , right)

        return root
            
                
            
            
                
        
                
            
            
            
            
