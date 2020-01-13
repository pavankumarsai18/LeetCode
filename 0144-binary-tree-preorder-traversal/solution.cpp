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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if(root == nullptr)
            return result;
        else
        {
            result.push_back(root->val);
            if(root->left != nullptr)
            {
                auto l = preorderTraversal(root->left);
                for(auto x: l)
                    result.push_back(x);
            }
            if(root->right != nullptr)
            {
                auto r = preorderTraversal(root->right);
                for(auto x: r)
                    result.push_back(x);
            }
            
            
            return result;
        }
        
    }
};
