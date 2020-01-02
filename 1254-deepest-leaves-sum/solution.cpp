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
    int level_order(TreeNode* & n)
    {
        if(n == nullptr)
            return 0;
        else
        {
            queue<TreeNode*> level;
            level.push(n);
            int sum = 0;
            
            while(level.size() != 0)
            {
                
                queue<TreeNode*> L;
                int leaves_sum = 0;
                while(level.size() != 0)
                {
                    TreeNode* node = level.front();
                    level.pop();
                    
                    if(node->left != nullptr)
                        L.push(node->left);
                    if(node->right != nullptr)
                        L.push(node->right);
                    
                    if(node->left == nullptr && node->right == nullptr)
                        leaves_sum += node->val;
                }
                level = L;
                sum = leaves_sum;
            }
            
            return sum;
        }
    }
    
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        return level_order(root);    
    }
};
