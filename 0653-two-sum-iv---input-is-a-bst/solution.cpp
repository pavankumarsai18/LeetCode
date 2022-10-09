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
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr) return;
        
        if(root->left) inorder(root->left, nums);
        
        nums.push_back(root->val);
        
        if(root->right) inorder(root->right, nums);
        
        return;
    }
public:
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> nums;
        inorder(root, nums);
        
        int left = 0, right = nums.size() -1;
        
        while(left < right)
        {
            if(nums[left] + nums[right] == k) return true;
            
            else if(nums[left] + nums[right] > k) right--;
            else left++;
        }
        
        return false;
        
    }
};
