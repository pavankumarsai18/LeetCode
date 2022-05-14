# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        nodeVertices = dict()
        
        def preOrderTraversal(node, vertLevel, depth):
            if node == None:
                return
            
            if node == root:
                nodeVertices[0] = [(root.val, depth)]
            elif node:
                if vertLevel not in nodeVertices:
                    nodeVertices[vertLevel] = []
                nodeVertices[vertLevel].append((node.val, depth))
            
            preOrderTraversal(node.left, vertLevel - 1, depth+1)
            preOrderTraversal(node.right, vertLevel + 1, depth+1)
            return 
        
        minVertical = 0
        preOrderTraversal(root, minVertical,0)
        
        
        result = []
        vertLev = min(nodeVertices.keys()) if len(nodeVertices) else -1      
    
        while vertLev in nodeVertices:
            vertices = [item[0] for item in sorted(nodeVertices[vertLev], key=lambda x: x[1])]
            
            result.append(vertices)
            vertLev += 1
        return result
                
