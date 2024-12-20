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
    void dfs(TreeNode* left_node, TreeNode* right_node, bool & is_odd) {
        if (left_node == nullptr || right_node == nullptr) {
            return;
        }
        if (is_odd) {
            swap(left_node->val, right_node->val);
        }

        bool copy_is_odd = is_odd;
        is_odd = !copy_is_odd;
        dfs(left_node->left, right_node->right, is_odd);
        
        is_odd = !copy_is_odd;
        dfs(left_node->right, right_node->left, is_odd);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        bool is_odd = true;
        dfs(root->left, root->right, is_odd);
        return root;
    }
};
