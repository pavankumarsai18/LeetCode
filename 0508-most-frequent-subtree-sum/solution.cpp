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
    bool isLeaf(TreeNode* root)
    {
        return (root && root->left == nullptr && root->right == nullptr);
    }
    
    int treeSum(TreeNode* root, unordered_map<int, int> & sumCount)
    {
        if(root == nullptr)
            return 0;

        int leftSum  = treeSum(root->left, sumCount);
        int rightSum = treeSum(root->right, sumCount);
        
        int treeSum = root->val + leftSum + rightSum;
        
        sumCount[treeSum]++;
        return treeSum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        unordered_map<int, int> sumCount;
        treeSum(root, sumCount);
        
        int maxFreq = -1;
        for(auto & [sum, freq]: sumCount)
        {
            maxFreq = max(maxFreq, freq);
        }
        
        vector<int> result;
        for(auto & [sum, freq]: sumCount)
        {
            if(freq == maxFreq)
                result.push_back(sum);
        }
        
        return result;
        
    }
};
