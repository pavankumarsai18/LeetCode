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
    int getHeight(TreeNode* node, unordered_map<TreeNode*, int> & heightMap)
    {
        if(node == nullptr) return -1;
        
        if(heightMap.find(node) != heightMap.end()) return heightMap[node];
        
        int height = max(getHeight(node->left, heightMap), getHeight(node->right, heightMap)) + 1;
        heightMap[node] = height;
        
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        unordered_map<TreeNode*, int> heightMap;
        
        int numRemovals = getHeight(root, heightMap);
        
        vector<vector<int>> ans(numRemovals + 1, vector<int>());
        
        for(auto & [node, height]: heightMap)
        {
            ans[height].push_back(node->val);
        }
        
        return ans;
        
    }
};
