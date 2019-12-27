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
    void postorder_trim(TreeNode* & n, int L, int R)
    {
        if(n == nullptr)
            ;//do nothing
        else 
        {
            if(n->left == nullptr && n->right == nullptr)
            {
                if(n->val < L || n->val > R)
                {
                    delete n;
                    n = nullptr;
                }
            }
            else if(n->left != nullptr && n->right == nullptr)
            {
                postorder_trim(n->left, L, R);
                if(n->val < L || n->val > R)
                {
                    
                    if(n->left == nullptr){
                        delete n;
                        n = nullptr;
                    }
                    else
                    {
                        auto temp_val = n->left->val;
                        auto temp_left = n->left->left;
                        auto temp_right = n->left->right;
                        
                        delete n->left;
                        n->val = temp_val;
                        n->left = temp_left;
                        n->right = temp_right;
                        
                        
                    }
                        
                }
            }
            else if(n->left == nullptr && n->right != nullptr)
            {
                postorder_trim(n->right, L, R);
                if(n->val < L || n->val > R)
                {
                    
                    
                    if(n->right == nullptr){
                        delete n;
                        n = nullptr;
                    }
                    else 
                    {
                        auto temp_val = n->right->val;
                        auto temp_left = n->right->left;
                        auto temp_right = n->right->right;
                        
                        delete n->right;
                        n->val = temp_val;
                        n->left = temp_left;
                        n->right = temp_right;
                        
                        
                    }
                        
                }
                
            }
            else
            {
                postorder_trim(n->left, L, R);
                postorder_trim(n->right, L, R);
                
                if(n->val < L || n->val > R)
                {
                    if(n->right == nullptr && n->left == nullptr)
                    {
                        delete n;
                        n = nullptr;
                    }
                    else if(n->right == nullptr && n->left != nullptr)
                    {
                        auto temp_val = n->left->val;
                        auto temp_l = n->left->left;
                        auto temp_r = n->left->right;
                        
                        delete n->left;
                        n->val = temp_val;
                        n->left = temp_l;
                        n->right = temp_r;
                    }
                    else if(n->right != nullptr && n->left == nullptr)
                    {
                        auto temp_val = n->right->val;
                        auto temp_l = n->right->left;
                        auto temp_r = n->right->right;
                        
                        delete n->right;
                        n->val = temp_val;
                        n->left = temp_l;
                        n->right = temp_r;
                    }
                    else
                    {
                        auto temp_val = n->left->val;
                        auto temp_l = n->left->left;
                        auto temp_r = n->left->right;
                        
                        delete n->left;
                        n->val = temp_val;
                        n->left = temp_l;
                        n->right = temp_r;
                    }
                }
            }
        }
    }
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) 
    {
        if(root == nullptr)
            return nullptr;
        // need to perform a preorder search
        // and delete nodes that are not not in range(L, R)
        postorder_trim(root, L, R);
        return root;
        
    }
};
