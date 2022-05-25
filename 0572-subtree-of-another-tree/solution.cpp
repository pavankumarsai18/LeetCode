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
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if(root1 && root2)
        {
            if(root1->val == root2->val)
            {
            return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
            }
            return false;
        }
        if(root1 == nullptr && root2 == nullptr)
            return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == nullptr && subRoot || subRoot == nullptr && root)
            return false;
        
        if(root == nullptr && subRoot == nullptr)
            return true;
    

        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
        {
            return true;
        }
        
        if(root->val == subRoot->val && isSame(root, subRoot))
            return true;        
        return false;
    }
};
