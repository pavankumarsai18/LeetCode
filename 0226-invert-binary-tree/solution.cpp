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
    TreeNode* invertTree(TreeNode* root) {
        return invertNode(root);
    }
    TreeNode* invertNode(TreeNode* & n)
    {
        if(n == nullptr)
            return nullptr;
        
        if(n->left == nullptr && n->right == nullptr)
        {
            return n;
        }
        else if(n ->left == nullptr && n->right != nullptr)
        {
            invertNode(n->right);
            TreeNode* temp = n->right;
            n->right = nullptr;
            n->left = temp;
        }
        else if(n ->right == nullptr && n ->left != nullptr)
        {
            invertNode(n->left);
            TreeNode* temp = n->left;
            n->left = nullptr;
            n->right = temp;
        }
        else
        {
            invertNode(n->left);
            invertNode(n->right);
            TreeNode* temp_l = n->left;
            n->left = n->right;
            n->right = temp_l;
        }
        return n;
    }
};
