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
    bool isLeaf(TreeNode* node)
    {
        return (node && node->left == nullptr && node->right == nullptr);
    }
    void flatten(TreeNode* root) 
    {
        if(root == nullptr) return;   
        if(root->left == nullptr && root->right == nullptr) return;
        else if(root->left == nullptr && isLeaf(root->right)) return;
        
        // cout<<root->val<<endl;
        TreeNode* leftNode  = root->left;
        TreeNode* rightNode = root->right;
        
        root->left = nullptr;
        root->right = nullptr;
        
        flatten(leftNode);
        flatten(rightNode);
        
        TreeNode* cur = leftNode;
        
        
        root->right = leftNode;
        if(root->right)
        {
            while(cur != nullptr && cur->right != nullptr)
            {
                cur = cur->right;
            }
            cur->right  = rightNode;
        }
        else
        {
            root->right = rightNode;
        }
        
        
        return;
        
    }
};
