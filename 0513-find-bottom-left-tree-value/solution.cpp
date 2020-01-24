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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> level;
        
        queue<TreeNode*> cpy;
        level.push(root);
        
        while(!level.empty())
        {
            cpy = level;
            queue<TreeNode*>temp;
            while(!level.empty())
            {
                auto n = level.front();
                level.pop();
                
                if(n->left != nullptr)
                    temp.push(n->left);
                if(n->right != nullptr)
                    temp.push(n->right);
                
            }
            level = temp;
        }
        
        return cpy.front()->val;
    }
};
