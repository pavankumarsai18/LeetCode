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
        vector<int> ans;
        
        
        TreeNode* node = root;
        
        
        while(node)
        {
            if(node->left)
            {
                TreeNode* pred = node->left;
                while(pred && pred->right && pred->right != node)
                {
                    pred = pred->right;
                }
                
                
                if(pred->right == node)
                {
                    pred->right = nullptr;

                    ans.push_back(node->val);
                    node = node->right;
                }
                else
                {
                    pred->right =  node;
                    node = node->left;
                }
                
            }
            else
            {
                ans.push_back(node->val);
                node = node->right;
            }
        }
        
        
        return ans;
    }
};
