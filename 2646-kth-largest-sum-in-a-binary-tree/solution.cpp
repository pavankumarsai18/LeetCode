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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        vector<long long> level_sums;
        queue<TreeNode*> level;

        level.push(root);
        while(!level.empty()) {
            long long level_sum = 0;
            queue<TreeNode*> next_level;

            while (!level.empty()) {
                TreeNode* node = level.front();
                level_sum += node->val;

                if (node->left) {
                    next_level.push(node->left);
                }

                if (node->right) {
                    next_level.push(node->right);
                }

                level.pop();
            }

            level_sums.push_back(level_sum);
            level = move(next_level);
        }

        if (level_sums.size() < k) {
            return -1;
        }


        std::nth_element(level_sums.begin(), level_sums.end() - k, level_sums.end());


        return level_sums[level_sums.size() - k];
    }
};
