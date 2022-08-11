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
    void getGoodNodes(TreeNode* node, int & maxValue, int & numGoodNodes)
    {
        if(node == nullptr) return;
        
        if(maxValue <= node->val) numGoodNodes++;
        
        int temp = maxValue;
        maxValue = max(maxValue, node->val);
        
        getGoodNodes(node->left, maxValue, numGoodNodes);        
        getGoodNodes(node->right, maxValue, numGoodNodes);

        maxValue = temp;
        
    }
    int goodNodes(TreeNode* root) 
    {        
        int ans = 0;
        int maxValue = root->val;
        getGoodNodes(root, maxValue, ans);
        
        return ans;
    }
};
