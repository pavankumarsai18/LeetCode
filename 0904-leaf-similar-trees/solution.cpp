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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        
        vector<int> a = leaf(root1);
        vector<int> b = leaf(root2);
        if(a.size() != b.size())
            return false;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])
                return false;
        
        return true;
    }
    
    vector<int> leaf(TreeNode* node)
    {
        if(node == nullptr)
            return vector<int>();
        else if(node->left == nullptr && node->right == nullptr)
        {
            vector<int> result;
            result.push_back(node->val);
            return result;
        }
        else
        {
            if(node->right == nullptr && node->left != nullptr)
            {
                vector<int> result = leaf(node->left);
                return result;
            }
            else if(node->left == nullptr && node->right == nullptr)
            {
                vector<int> result = leaf(node->right);
                return result;
            }
            else
            {
                vector<int> result = leaf(node->left);
                vector<int> temp = leaf(node->right);
                for(int i = 0; i < temp.size();i++)
                {
                    result.push_back(temp[i]);
                }
                
                return result;
            }
                
        }
    }
    
};
