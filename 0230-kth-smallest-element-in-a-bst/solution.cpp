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
    int kthSmallest(TreeNode* root, int k) {
        // Go as left as you can
        // Go to parent
        // Go right and as left as you can
        // Go to parent
        stack<TreeNode*> S;
        while (true) {
            while (root != nullptr) {
                S.push(root);
                root = root->left;
            }
            root = S.top(); S.pop();
            k--;
            if (k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};
