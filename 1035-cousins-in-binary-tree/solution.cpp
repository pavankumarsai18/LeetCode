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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        int lev_x = 0;
        int lev_y = 0;
        TreeNode* par_x = nullptr;
        TreeNode* par_y = nullptr;
        
        queue<TreeNode*> lev;
        int level = 0;
        lev.push(root);
        while(lev.size() != 0)
        {
            
            queue<TreeNode*> temp;
            while(lev.size() != 0)
            {
                auto node = lev.front();
                lev.pop();
                if(node->left != nullptr && (node->left->val == x || node->left->val == y))
                {
                    if(node->left->val == x){
                        lev_x = level;
                        par_x = node;
                    }
                    else{
                        lev_y = level;
                        par_y = node;
                    }
                }
                else if(node->right != nullptr && (node->right->val == x || node->right->val ==y))
                {
                    if(node->right->val == x){
                        lev_x = level;
                        par_x  = node;
                    }
                    else{
                        lev_y = level;
                        par_y = node;
                    }
                }
                
                if(lev_x != 0 && lev_y != 0)
                {
                    if(lev_x == lev_y)
                    {
                        if(par_x != par_y)
                            return true;
                        else
                            return false;
                    }
                    return false;
                }
                
                if(node->left != nullptr)
                    temp.push(node->left);
                if(node->right != nullptr)
                    temp.push(node->right);
            }
            level++;
            lev = temp;
        }
        return false;
    }
};
