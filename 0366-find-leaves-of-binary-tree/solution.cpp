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
private:
    int postOrder(TreeNode* root, vector<vector<int>> & result)
    {
        if(root == nullptr)
            return 0;
        
        int curNodeHeight = max(postOrder(root->left, result), postOrder(root->right, result)) + 1;
        
        if(result.size() < curNodeHeight)
        {
            result.push_back({});
        }
        result[curNodeHeight-1].push_back(root->val);
        return curNodeHeight;
        
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        vector<vector<int>> result;
        postOrder(root, result);
        return result;
        
    }
};
