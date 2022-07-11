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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == nullptr)
            return {};
        vector<int> ans;
        vector<TreeNode*> level;
        
        level.push_back(root);
    
        
        while(!level.empty())
        {
            ans.push_back(level[level.size()-1]->val);
            vector<TreeNode*> newLevel;
            for(int i = 0; i < level.size(); i++)
            {
                TreeNode* node = level[i];
                if(node->left)
                    newLevel.push_back(node->left);
                if(node->right)
                    newLevel.push_back(node->right);
            }
            
            level = newLevel;
        }
        
        return ans;
        
    }
};
