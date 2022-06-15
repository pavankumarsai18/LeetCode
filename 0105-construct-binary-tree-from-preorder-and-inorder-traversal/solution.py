# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        inorderMap = defaultdict(int)
        for index, val in enumerate(inorder):
            inorderMap[val] = index
        
        def arrToTree(left, right):
            nonlocal preorderIndex
            if left > right:
                return None
            
            root = TreeNode(preorder[preorderIndex])
            preorderIndex += 1
            
            index   = inorderMap[root.val]
            root.left  = arrToTree(left, index-1)
            root.right = arrToTree(index+1, right)
            
            return root
            
        
        preorderIndex = 0
        return arrToTree(0, len(preorder)-1)
        
        
