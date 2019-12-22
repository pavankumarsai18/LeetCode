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
    void preorder(TreeNode* n, vector<vector<TreeNode*>> & paths, vector<TreeNode*>&cur_path)
    {
        if(n == nullptr)
            return;
        else
        {
            if(n->left == nullptr && n->right != nullptr)
            {
                cur_path.push_back(n);
                preorder(n->right, paths, cur_path);
            }
            else if(n->left != nullptr && n->right == nullptr)
            {
                cur_path.push_back(n);
                preorder(n->left, paths, cur_path);
            }
            else if(n->left == nullptr && n->right == nullptr)
            {
                cur_path.push_back(n);
                paths.push_back(cur_path);
            }
            else
            {
                cur_path.push_back(n);
                auto temp = cur_path;
                
                preorder(n->left,paths, cur_path);
                preorder(n->right, paths, temp);
            }
        }
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        vector<vector<TreeNode*>> paths;
        vector<TreeNode*>cur_path;
        preorder(root, paths, cur_path);
        
        //cout<<paths.size();
        int sum_paths = 0;
        for(int i = 0; i < paths.size(); i++)
        {
            int result = 0;
            for(int j = 0; j < paths[i].size(); j++)
            {
                result += paths[i][j]->val;
                if(j != paths[i].size() - 1)
                    result <<= 1;
            }
            sum_paths += result;
        }
        return sum_paths;
       
    }
};
