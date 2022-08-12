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
    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*> & path)
    {
        if(root == nullptr) return false;
        
        if(root == target)
        {
            path.push_back(root);
            return true;
        }
        
        if(find(root->left, target, path) || find(root->right, target, path))
        {
            path.push_back(root);
            return true;
        }
        
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> pPath, qPath;
        find(root, p, pPath);
        find(root, q, qPath);
        
        
        int pIndex, qIndex;
        pIndex = pPath.size() - 1;
        qIndex = qPath.size() - 1;
        
        // 2 6
        // 8 6
        
        while(pIndex >= 0 && qIndex >= 0&& qPath[qIndex] == pPath[pIndex])
        {
            pIndex--;
            qIndex--;
        }
        
        return pPath[pIndex+1];
        
        
    }
};
