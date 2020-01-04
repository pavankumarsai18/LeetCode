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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> level_trav;
        if(root == nullptr)
            return level_trav;
        
        deque<TreeNode*> level;
        level.push_back(root);
        while(level.size() != 0)
        {
            vector<int> temp;
            for(auto itr = level.begin(); itr != level.end(); itr++)
            {
                temp.push_back( (*itr)->val);
            }
            level_trav.push_back(temp);
            
            deque<TreeNode*> T;
            while(level.size() != 0)
            {
                auto node = level.front();
                level.pop_front();
                if(node->left != nullptr)
                    T.push_back(node->left);
                if(node->right != nullptr)
                    T.push_back(node->right);
            }
            level = T;
        }
        
        return level_trav;
        
    }
};
