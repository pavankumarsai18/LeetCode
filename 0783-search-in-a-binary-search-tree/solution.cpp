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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            return nullptr;
        }
        TreeNode* curNode = root;
        
        while(curNode)
        {
            if(curNode->val == val)
            {
                return curNode;
            }
            else if(curNode->val > val)
            {
                curNode = curNode->left;
            }
            else if(curNode->val < val)
            {
                curNode = curNode->right;
            }
        }
        
        return nullptr;
    }
};
