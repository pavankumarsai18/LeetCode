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
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> visited;
        unordered_set<int> toFind;
        
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            queue<TreeNode*> Temp;
            while(!Q.empty())
            {
                auto n = Q.front();
                
                visited.insert(n->val);
                if(toFind.find(n->val) != toFind.end())
                {
                    return true;
                }
                if(n->left != nullptr)
                {
                    Temp.push(n->left);
                }
                if(n->right != nullptr)
                {
                    Temp.push(n->right);
                }
                Q.pop();
                
                toFind.insert(k - n->val);
            }
            
            Q = Temp;
        }
        return false;
        
        
    }
};
