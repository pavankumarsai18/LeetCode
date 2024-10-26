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
public:
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

    bool findNode(TreeNode* root, TreeNode* node, vector<TreeNode*> & ancestors) {
        if (root == nullptr) {
            return false;
        }


        ancestors.push_back(root);
        if (root == node) {
            return true;
        }
        if (node->val < root->val) {
            bool foundLeft  = findNode(root->left, node, ancestors);
            if (!foundLeft) {
                ancestors.pop_back();
            }
            return foundLeft;
        }

        bool foundRight = findNode(root->right, node, ancestors);
        if (!foundRight) {
            ancestors.pop_back();
        }
        return foundRight;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pAncestors, qAncestors;
        findNode(root, p, pAncestors);
        findNode(root, q, qAncestors);

        int p_idx = 0, q_idx = 0;
        TreeNode* lca = nullptr;
        while (p_idx < pAncestors.size() && q_idx < qAncestors.size() && pAncestors[p_idx] == qAncestors[q_idx]) {
            lca = pAncestors[p_idx];
            p_idx++;
            q_idx++;
        }

        return lca;
    }

};
