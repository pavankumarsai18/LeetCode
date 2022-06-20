# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def totalWays(root, cur_sum, cache):
            nonlocal count
            if not root:
                return
            
            cur_sum += root.val
            
            if cur_sum == targetSum:
                count += 1
            
            count += cache[cur_sum - targetSum]
            
            cache[cur_sum] += 1
            
            totalWays(root.left, cur_sum, cache)
            totalWays(root.right, cur_sum, cache)
            
            cache[cur_sum] -= 1

            
            
        count = 0
        cache = defaultdict(int)
        totalWays(root, 0, cache)
        return count
