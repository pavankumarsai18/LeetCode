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
private:
    void prefix(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* & result)
    {
        if(original == target)
        {
            result = cloned;
            return;
        }
        else
        {
            if(original != nullptr && cloned != nullptr)
            {
                if(original->left != nullptr && cloned->left != nullptr)
                {
                    prefix(original->left, cloned->left, target, result);
                }
                if(original->right != nullptr && cloned->right != nullptr)
                {
                    prefix(original->right, cloned->right, target, result);
                }
            }
        }
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        TreeNode* result;
        prefix(original, cloned, target, result);
        return result;
    }
};
