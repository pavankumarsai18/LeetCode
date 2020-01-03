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
    void levelorder(TreeNode*& n, int v, int d)
    {
        if(n == nullptr)
        {
            n = new TreeNode(v);
            return;
        }
        else
        {
            int level = 1;
            queue<TreeNode*> L;
            L.push(n);
            
            
            while(L.size() != 0)
            {
                queue<TreeNode*> temp;
                if(level != d - 1)
                {
                    while(L.size() != 0)
                    {
                        TreeNode* node = L.front();
                        L.pop();
                        if(node->left != nullptr)
                            temp.push(node->left);
                        if(node->right != nullptr)
                            temp.push(node->right);
                    }
                    level++;
                    L = temp;
                }
                else
                {
                    while(L.size() != 0)
                    {
                        TreeNode*node = L.front();
                        L.pop();
                        
                        TreeNode* n_left = new TreeNode(v);
                        n_left->left = node->left;
                        
                        TreeNode* n_right = new TreeNode(v);
                        n_right->right = node->right;
                        
                        node->left = n_left;
                        node->right = n_right;  
                    }
                    
                    break;
                }
            }
            
            
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* r = new TreeNode(v);
            r->left = root;
            r->right = nullptr;
            return r;
        }
        levelorder(root, v, d);
        return root;
    }
};
