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
private:
    void inorder(TreeNode* &root, vector<TreeNode*>& M, int& sum)
    {
        if(root != nullptr)
        {    
            if(root->left != nullptr)
                inorder(root->left, M, sum);
            
            sum += root->val;
            M.push_back(root);
        
            if(root->right != nullptr)
                inorder(root->right, M, sum); 
        }
            
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> M;
        int sum = 0;
        inorder(root, M, sum);
        
        for(int i = 0; i < M.size(); i++)
        {
            int temp = M[i]->val;
            M[i]->val = sum;
            sum -= temp;
        }
        return root;
    }
};
