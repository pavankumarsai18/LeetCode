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
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if(root == nullptr) return {};
        
        
        map<int, vector<int>> nodePos;
        
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        
        int col;
        while(!Q.empty())
        {
            pair<TreeNode*, int> item = Q.front();
            Q.pop();
            
            col        = item.second;
            TreeNode* node = item.first;
            
            nodePos[col].push_back(node->val);
            
            if(node->left) Q.push({node->left, col-1});
            
            if(node->right) Q.push({node->right, col+1});
        }
        
        
        vector<vector<int>> ans;
        
        for(auto itr = nodePos.begin(); itr != nodePos.end(); itr++)
        {
            ans.push_back(itr->second);
        }
        
        return ans;
        
        
    }
};
