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
    // bool static less(int & a, int & b)
    // {
    //     return a <= b;
    // }
    int preorder(TreeNode* n, int & diff)
    {
        if(n == nullptr)
            return diff;
        else
        {
            // cout<<n->val<<" "<<diff<<endl;
            int d_3 = diff;
            
            if(n->left != nullptr)
            {
                auto cur = n->left;
                auto prev = cur;
                while(cur != nullptr)
                {
                    prev = cur;
                    cur = cur->right;
                }
                
               if(d_3 > (n->val - prev->val))
               {
                   d_3 = n->val - prev->val;
                   diff = d_3;
               }
                
                
            }

            
            if(n->right != nullptr)
            {
                auto cur = n->right;
                auto prev = cur;
                while(cur != nullptr)
                {
                    prev = cur;
                    cur = cur->left;
                }
                
                if(d_3 > (prev->val - n->val)){
                    d_3 = prev->val - n->val;
                    diff = d_3;
                }
            }
            
            int d_1 = d_3;
            int d_2 = d_3;
            
            if(n->left != nullptr && (n->left->left != nullptr || n->left->right != nullptr))
                d_1 = preorder(n->left, diff);
            if(n->right != nullptr && (n->right->left != nullptr || n->right->right != nullptr))
                d_2 = preorder(n->right, diff);
            
            return abs(min({abs(d_1), abs(d_2), abs(diff), abs(d_3)}));

        }
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        
        int diff = 2000000000;
        int result = preorder(root, diff);
        return result;
    }
};
