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
    void preOrderTraversal(TreeNode* original, TreeNode* cloned, int targetVal, TreeNode* & result)
    {
        if(original == nullptr)
            return;
        
        if(original->val == targetVal)
        {
            result = cloned;
            return;
        }
       preOrderTraversal(original->left, cloned->left, targetVal, result);
       preOrderTraversal(original->right, cloned->right, targetVal, result);
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(original == cloned)
            return cloned;
        
        TreeNode* result = nullptr;
        preOrderTraversal(original, cloned, target->val, result);
        return result;
        
    }
};
