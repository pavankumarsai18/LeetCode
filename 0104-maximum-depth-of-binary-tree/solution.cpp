/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max(int A, int B)
    {
        if(A > B)
            return A;
        else
            return B;
    }
    int maxDepth(TreeNode* root) 
    {
        return Depth(root);
    }
    int Depth(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        else
            return max(Depth(node->right), Depth(node->left)) + 1;
    }
    
};
