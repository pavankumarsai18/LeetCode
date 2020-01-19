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
    void preorder(unordered_set<TreeNode*>& S, TreeNode*& n, int & target)
    {
        if(n == nullptr)
        {
            return;
        }
        else
        {
            if(n->left != nullptr)
            {
                if(n->left->left == nullptr && n->left->right == nullptr && n->left->val == target)
                {
                    S.insert(n);
                }
                else
                {
                    preorder(S, n->left, target);
                }
            }
            if(n->right != nullptr)
            {
                if(n->right->right == nullptr && n->right->left == nullptr && n->right->val == target)
                {
                    S.insert(n);
                }
                else
                {
                    preorder(S, n->right, target);
                }
            }
            
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        if(root == nullptr)
            return root;
        
        unordered_set<TreeNode*> leaves;
        bool possible = true;
        do
        {   
            preorder(leaves, root, target);
            if(leaves.empty())
            {
                break;
            }
            
            else
            {
                for(auto itr = leaves.begin(); itr != leaves.end(); itr++)
                {
                    auto node = *itr;
                    if(node->left != nullptr && node->left->val == target)
                    {
                        if( node->left->left == nullptr && node->left->right == nullptr)
                        {
                            delete node->left;
                            node->left = nullptr;
                        }
                    }
                           
                    if(node->right != nullptr &&  node->right->val == target)
                    {
                        if(node->right ->left == nullptr && node->right->right == nullptr)
                        {
                            delete node->right;
                            node->right = nullptr;
                        }
                    }
                }
                leaves = unordered_set<TreeNode*>();
            }
            
        }while(possible);
        // cout<<"Out of the loop\n";
        
        if(root->val == target && root->left == nullptr && root->right == nullptr)
        {
            //delete root;
            return nullptr;
        }
        return root;
        
    
    }
};
