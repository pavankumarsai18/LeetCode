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
    void Binary_paths(vector<string>& S, TreeNode* n)
    {
        queue<TreeNode*> Q;
        Q.push(n);
        unordered_map<TreeNode*, string> result;
        result[n] = to_string(n->val);
    
        while(!Q.empty())
        {
            queue<TreeNode*> temp;
            while(!Q.empty())
            {
                auto n = Q.front();
                Q.pop();
                if(n->left != nullptr)
                {
                    string cpy_lft = result[n];
                    cpy_lft += "->" + to_string(n->left->val);
                    result[n->left] = cpy_lft;
                    temp.push(n->left);
                    
                    
                }
                if(n->right != nullptr)
                {
                    string cpy_rgt = result[n];
                    cpy_rgt += "->" + to_string(n->right->val);
                    result[n->right] = cpy_rgt;
                    temp.push(n->right);
                }
                if(n->left != nullptr || n->right != nullptr){
                    result.erase(n);
                }
            }
            Q = temp;
        }
        
        for(auto itr = result.begin(); itr != result.end(); itr++)
        {
            S.push_back(itr->second);
        }
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        
        vector<string> result;
        if(root != nullptr)
            Binary_paths(result, root);
        return result;
    }
};
