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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        TreeNode* result = nullptr;
        TreeNode* curr_1 = t1;
        TreeNode* curr_2 = t2;
        result = mergeNodes(t1, t2);
        return result;
    }
    
    TreeNode* mergeNodes(TreeNode*& r1, TreeNode*& r2)
    {
        if(r1 == nullptr && r2 == nullptr)
            return nullptr;
        else if(r1 == nullptr && r2 != nullptr)
        {
            return r2;
        }
        else if(r1 != nullptr && r2 == nullptr)
        {
            return r1;
        }
        else
        {
            TreeNode* r3 = new TreeNode(r1->val+r2->val);
            r3->left = mergeNodes(r1->left, r2->left);
            r3->right = mergeNodes(r1->right, r2->right);
            return r3;
        }
    }
};
