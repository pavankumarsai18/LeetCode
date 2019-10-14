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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result = nullptr;
        TreeNode* curr_node = root;
        while(curr_node != nullptr)
        {
            if(curr_node->val < val)
            {
                curr_node = curr_node->right;
            }
            else if(curr_node->val > val)
            {
                curr_node = curr_node->left;
            }
            else
            {
                result = curr_node;
                break;
            }
        }
        return result;
                                        
        
    }
};
