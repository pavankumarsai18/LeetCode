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
    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*> & path)
    {
        if(root == nullptr || target == nullptr) 
            return;
        
        path.push_back(root);

        if(root->val == target->val)
        {
            return;
        }
        else
        {               
            if(target->val > root->val)
            {
                findPath(root->right, target, path);
            }
            else if(target->val < root->val)
            {
                findPath(root->left, target, path);
            }
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == nullptr)
            return nullptr;
        
        
        vector<TreeNode*> pPath;
        findPath(root, p, pPath);
        
        if(pPath.size() == 0)
            return nullptr;
        
        
        vector<TreeNode*> qPath;
        findPath(root, q, qPath);
        
        if(qPath.size() == 0)
            return nullptr;
        
        
        TreeNode* result = nullptr;
        
        vector<TreeNode*> largePath = pPath;
        vector<TreeNode*> smallPath = qPath;
        
        
        if(qPath.size() > pPath.size())
        {
            largePath = qPath;
            smallPath = pPath;
        }

        for(int i = 0; i < smallPath.size(); i++)
        {
            if(largePath[i]->val == smallPath[i]->val)
            {
                result = largePath[i];
            }
        }
        
        return result;
        
    }
};
