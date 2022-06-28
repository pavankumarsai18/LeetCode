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
    void sumNumbers(TreeNode* root, int & curSum, int& totalSum)
    {
        if(root == nullptr)
        {
            return;
        }
        else if(root->left == nullptr && root->right == nullptr)
        {
            curSum = curSum*10 + root->val;
            totalSum += curSum;
            return;
        }
        
        int copy = curSum;
        
        curSum = curSum*10 + root->val;
        sumNumbers(root->left, curSum, totalSum);
        
        curSum = copy*10 + root->val;
        sumNumbers(root->right, curSum, totalSum);
    }
    int sumNumbers(TreeNode* root) 
    {
        int curSum, totalSum;
        curSum = totalSum = 0;
        sumNumbers(root, curSum, totalSum);
        return totalSum;
    }
};
