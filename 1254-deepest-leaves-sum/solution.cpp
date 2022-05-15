/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root, int depth)
    {
        if(root == nullptr)
            return depth -1;
        
        return max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1));
    }
    
    void preOrderTraversal(TreeNode* node, int depth, const int treeDepth, int & leavesSum)
    {
        if(node == nullptr)
            return;
        
        if(depth == treeDepth)
        {
            leavesSum += node->val;
            return;
        }

        preOrderTraversal(node->left, depth + 1, treeDepth, leavesSum);
        preOrderTraversal(node->right, depth + 1, treeDepth, leavesSum);
        
    }
    
    
    int deepestLeavesSum(TreeNode* root) 
    {
        const int treeDepth = maxDepth(root, 0);
        int leavesSum = 0;
        preOrderTraversal(root,0 , treeDepth, leavesSum);
        return leavesSum;
        
    }
};
