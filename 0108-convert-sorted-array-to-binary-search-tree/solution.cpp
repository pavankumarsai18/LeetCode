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
private:
    // included range
    // [ ]
    vector<bool> covered;
    
    TreeNode* createTree(vector<int>& nums, int i, int j, vector<bool>&covered)
    {
        if(i < 0 || j >= nums.size())
        {
            return nullptr;
        }
        if(i == j)
        {
            covered[i] = true;
            return new TreeNode(nums[i]);
        }
        if(covered[(i+j)/2] == false)
        {
            TreeNode* root = new TreeNode(nums[(i+j)/2]);
            covered[(i+j)/2] = true;
            root->left = createTree(nums, i , (i+j)/2 - 1, covered);
            root->right = createTree(nums, (i+j)/2 + 1, j, covered);
            return  root;
        }
        else
            return nullptr;
       
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        // Insert nodes at midpoints
        // Make mid point of the arr the root
        // Two pointer Binary search
        for(int i = 0; i < nums.size(); i++)
        {
            this->covered.push_back(false);
        }
        return createTree(nums, 0, nums.size() - 1, covered);
           
    }
};
