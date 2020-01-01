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
    void postorder(TreeNode* &n)
    {
        if(n == nullptr)
            return;
        else
        {
            if(n->left == nullptr && n->right != nullptr)
            {
                postorder(n->right);
                if(n->right == nullptr && n->val == 0)
                {
                    delete n;
                    n = nullptr;
                }
            }
            else if(n->left == nullptr && n->right == nullptr)
            {
                if(n->val == 0)
                {
                    delete n;
                    n = nullptr;
                }
            }
            else if(n->left != nullptr && n->right == nullptr)
            {
                postorder(n->left);
                if(n->left == nullptr && n->val == 0)
                {
                    delete n;
                    n = nullptr;
                }
            }
            else
            {
                postorder(n->left);
                postorder(n->right);
                if(n->left == nullptr && n->right == nullptr && n->val == 0)
                {
                    delete n;
                    n = nullptr;
                }
            }
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) 
    {
        
        postorder(root);
        return root;
    }
};
