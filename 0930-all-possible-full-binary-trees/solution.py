# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.cache = dict()
    
    def copyTree(self, n):
        copy = None
        if n:
            copy = TreeNode(n.val)
            copy.left = self.copyTree(n.left)
            copy.right = self.copyTree(n.right)
        return copy
    
    def allLeaves(self, tree, leaves):
        if not tree:
            return
        else:
            if tree.left==None and tree.right==None:
                leaves.append(tree)
            else:
                self.allLeaves(tree.left, leaves)
                self.allLeaves(tree.right, leaves)
    def toStr(self, tree):
        result = ""
        if tree:
            result += str(tree.val)
            result += ","
            result += self.toStr(tree.left)
            result += ","
            result += self.toStr(tree.right)
        else:
            result += "null"
        return result
    
    def allPossibleFBT(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        self.__init__()
        
        if n in self.cache:
            return self.cache[n]
        elif n == 1:
            tree = TreeNode(0)
            return [tree]
        
        elif n == 3:
            tree = TreeNode(0, TreeNode(0),TreeNode(0))
            return [tree]
        
        allTrees = set()
        result = []
        if n - 2 > 0:
            temp = self.allPossibleFBT(n - 2)
            
            for tree in temp:
                leaves = list()
                self.allLeaves(tree, leaves)
                for node in leaves:
                    node.left, node.right = TreeNode(0), TreeNode(0)
                    copy = self.copyTree(tree)
                    
                    stringTree = self.toStr(copy)
                    if stringTree not in allTrees:
                        allTrees.add(stringTree)
                        result.append(copy)
                    
                    node.left, node.right = None, None
    
        self.cache[n] = result
        return result
        
