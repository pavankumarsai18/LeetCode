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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        insert(root, val);
        return root;
    }
    
    void insert(TreeNode* & node, int val)
    {
        if(node == nullptr)
        {
            return;
        }
        //cout<<node->val<<" ";
        if(node->val > val)
        {
            if(node->left != nullptr)
                insert(node->left, val);
            else
            {
                TreeNode * new_node = new TreeNode(val);
                node->left = new_node;
            }
        }
        
        else if(node->val < val)
        {
            if(node->right != nullptr)
                insert(node->right, val);
            else
            {
                TreeNode* new_node = new TreeNode(val);
                node->right = new_node;
            }
        }
    }
};
