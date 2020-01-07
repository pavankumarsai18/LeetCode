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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        
        queue<TreeNode*> L;
        L.push(root);
        
        while(!L.empty())
        {
            queue<TreeNode*> temp;
            vector<int> level;
            while(!L.empty())
            {
                auto node = L.front();
                level.push_back(node->val);
                L.pop();
                if(node->left != nullptr)
                {
                    temp.push(node->left);
                }
                if(node->right != nullptr)
                {
                    temp.push(node->right);
                }
            }
            L = temp;
            result.push_back(level);
        }
        
        for(int i = 0; i < result.size()/2; i++)
        {
            swap(result[i], result[result.size() - 1 - i]);
        }
        
        return result;
    }
};
