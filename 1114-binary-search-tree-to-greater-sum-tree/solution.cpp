/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
private:
    void inorder_traversal(TreeNode* root, vector<int>& values, unordered_map<int, TreeNode*>& index_node)
    {
        if(root == nullptr)
            return;
        else
        {
            inorder_traversal(root->left, values, index_node);
            
            values.push_back(root->val);
            index_node[values.size()-1] = root;
            
            inorder_traversal(root->right, values, index_node);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        //First we perform a preorder traversal and sttore the values in an array
        vector<int> values;
        unordered_map <int, TreeNode*> index_node;
        inorder_traversal(root, values, index_node);
            
        int sum = 0;
        for(int &x:values)
        {
            sum += x;
        }
        
        // 0 1 2 3 4 5 6 7 8
        vector<int> result_val;
        for(int i = 0; i < values.size(); i++)
        {
            if(result_val.size() == 0)
            {
                result_val.push_back(0); 
            }
            else
            {
                result_val.push_back(result_val[result_val.size()-1]+values[i-1]);
                
            }            
        }
        for(int& x: result_val)
        {
            x = sum - x;
        }
        
        for(int i = 0; i < result_val.size(); i++)
        {
            index_node[i]->val = result_val[i];
        }
        
        return root;
        
        
    }

};
