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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> Q;

        Q.push(root);
        while (Q.size() != 0) {
            queue<TreeNode*> nextLevel;
            if (Q.back() != nullptr) {
                ans.push_back(Q.back()->val);
            }
            while (Q.size() != 0) {
                TreeNode* node = Q.front(); Q.pop();
                if (node->left) {
                    nextLevel.push(node->left);
                }
                if (node->right) {
                    nextLevel.push(node->right);
                }
            }
            Q = std::move(nextLevel);
        }

        return ans;
    }
};

