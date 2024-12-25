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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<int> ans;
        deque<TreeNode*> level;
        level.push_back(root);

        while (!level.empty()) {
            int cur_max = level.front()->val;
            int level_elements = level.size();
            for (int i = 0; i < level_elements; ++i) {
                TreeNode* node = level.front();
                level.pop_front();
                if (node->val > cur_max) {
                    cur_max = node->val;
                }
                if (node->left) level.push_back(node->left);
                if (node->right) level.push_back(node->right);
            }
            ans.push_back(cur_max);
        }

        return ans;
    }
};
