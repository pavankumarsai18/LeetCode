# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:        
        # Post order L R P
        # In order   L P R
        
        inorder_map = defaultdict(int)
        postorder_map = defaultdict(int)
        
        for index, val in enumerate(inorder):
            inorder_map[val] = index
        
        
        def arrToTree(leftIn, rightIn):
            if leftIn > rightIn:
                return None
            
            rootVal = postorder.pop()
            root = TreeNode(rootVal)

            index = inorder_map[rootVal]
            
            root.right = arrToTree(index+1, rightIn)
            root.left  = arrToTree(leftIn, index-1)

            return root
        
        n = len(postorder)
        return arrToTree(0, n-1)
        
