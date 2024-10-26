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
    bool helper(TreeNode* root, long long L, long long R) {
        if (root == nullptr) return true;

        if (L < root->val && root->val < R) {
            return helper(root->left, L, root->val) && helper(root->right, root->val, R);
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long L = LLONG_MIN, R = LLONG_MAX;
        return helper(root, L, R);
    }
};

