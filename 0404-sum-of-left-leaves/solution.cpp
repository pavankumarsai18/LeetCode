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
    void preorder(TreeNode* n, int & sum)
    {
        if(n == nullptr)
        {;
        }
        else
        {
            if(n->left != nullptr)
            {
                if(n->left->left == nullptr && n->left->right == nullptr)
                {
                    sum += n->left->val;   
                }
                else
                {
                    preorder(n->left, sum);
                }
            }
            preorder(n->right, sum);
        }
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int s = 0;
        preorder(root, s);
        return s;
    }
};
