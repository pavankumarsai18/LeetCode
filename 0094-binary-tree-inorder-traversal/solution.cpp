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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> inorder;
        
        while(root)
        {
            if(root->left)
            {
                TreeNode* parent = root->left;
                while(parent->right && parent->right != root)
                {
                    parent = parent->right;
                }
                
                if(parent->right == nullptr)
                {
                    parent->right = root;
                    root = root->left;
                }
                else
                {
                    parent->right = nullptr;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
            else
            {
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        
        return inorder;
        
    }
};
