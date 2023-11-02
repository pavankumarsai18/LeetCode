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
    pair<int, int> sumTree(TreeNode* root, int & numAvg) {
        if (root == nullptr) return {0, 0};

        auto [numLeft, sumLeft]  = sumTree(root->left, numAvg);
        auto [numRight, sumRight] = sumTree(root->right, numAvg);

        const int totalNodes = (numLeft + numRight + 1);
        const int totalValue = (sumLeft + sumRight + root->val);

        int averageValue = totalValue/totalNodes;
        if (averageValue == root->val) {
            numAvg++;
        }

        return {totalNodes, totalValue};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto [totalNodes, totalSum] = sumTree(root, ans);
        return ans;    
    }
};
