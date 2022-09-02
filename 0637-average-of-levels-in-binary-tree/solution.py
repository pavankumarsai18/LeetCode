# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        
        Q   = collections.deque()
        ans = []
        
        
        Q.append(root)
        
        while Q:
            avg  = 0.0
            n    = len(Q)
            
            nextLevel = collections.deque()
            
            while Q:
                node = Q.popleft()
                avg  += node.val
                
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
                    
            avg /= n
            ans.append(avg)
            Q = nextLevel
        
        return ans
        
