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
    int max_gain(TreeNode* node, int & max_sum)
    {
        if(node == nullptr) return 0;
        
        
        int left_sum = max_gain(node->left, max_sum);
        int right_sum = max_gain(node->right, max_sum);
        
        left_sum = max(left_sum, 0);
        right_sum = max(right_sum, 0);
        
        max_sum = max(max_sum, node->val + left_sum + right_sum);
        
        return node->val + max(left_sum, right_sum);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int max_sum = INT_MIN;
        
        max_gain(root, max_sum);
        
        return max_sum; 
    }
};
