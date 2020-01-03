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
    bool preorder(TreeNode* &p, TreeNode* &q)
    {
        if(p == nullptr && q != nullptr)
            return false;
        if(p != nullptr && q == nullptr)
            return false;
        if(p == nullptr && q == nullptr)
            return true;
        else if(p != nullptr && q != nullptr)
        {
            if(p->val == q->val)
            {
                return preorder(p->left, q->left) &&  preorder(p->right, q->right);
            }
            else
            {
                return false;
            }
        }
        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        return preorder(p, q);
    }
};
