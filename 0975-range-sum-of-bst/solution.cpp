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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return 0;
        int result = 0;
        Visit(root, result, L, R);
        return result;
    }
    void Visit(TreeNode* node, int & result, const int& L, const int& R)
    {
        
        if(node->left == nullptr && node->right == nullptr)
        {
            
            if(node->val >= L && node->val <= R)
                result += node->val;
            //cout<<result<<" ";
            return;
            
            
        }
        else if(node->left == nullptr)
        {

            Visit(node->right, result, L, R);
            if(node->val >= L && node->val <= R)
                result += node->val;
            //cout<<result<<" ";
        }
        else if(node->right == nullptr)
        {
            Visit(node->left, result, L, R);
            if(node->val >= L && node->val <= R)
                result += node->val;
            //cout<<result<<" ";
        }
        
        else
        {
            Visit(node->left, result, L, R);
            Visit(node->right, result, L, R);
            if(node->val >= L && node->val <= R)
                result += node->val;
            //cout<<result<<" ";
        }
    }
};
