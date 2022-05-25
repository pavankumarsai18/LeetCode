# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        curLevel = deque()
        curLevel.append(root)
        
        treeNodes = []
        
        while curLevel:
            nextLevel = deque()
            
            level = []
            for item in curLevel:
                level.append(item)
            
            while curLevel:
                node = curLevel.popleft()
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            
            treeNodes.append(level)
            
            curLevel = nextLevel
        result = []
        i = 0
        while i < len(treeNodes):
            level = []
            if i&1 == 0:
                for j in range(len(treeNodes[i])):
                    level.append(treeNodes[i][j].val)
            else:
                for j in range(len(treeNodes[i])-1,-1,-1):
                    level.append(treeNodes[i][j].val)
            result.append(level)
            i += 1
        return result
        
