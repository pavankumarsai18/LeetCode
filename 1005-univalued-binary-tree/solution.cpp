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
    bool isUnivalTree(TreeNode* root) {
          return isUnivalNode(root);
    }
    bool isUnivalNode(TreeNode* & node)
    {
        if(node == nullptr)
        {
                return true;
        }
        else if(node->left != nullptr && node->right == nullptr)
        {
            
            if(isUnivalNode(node->left) && node->val == node->left->val)
                return true;
            return false;
        }
        else if(node->left == nullptr && node->right != nullptr)
        {
            if(isUnivalNode(node->right) && node->val == node->right->val)
                return true;
            return false;
        }
        else
        {
            if(node->left == nullptr && node->right == nullptr)
                return true;
            else if(isUnivalNode(node->right) && isUnivalNode(node->left) && node->val == node->left->val && node->right->val == node->val)
                return true;
            return false;
        }
    }
};
