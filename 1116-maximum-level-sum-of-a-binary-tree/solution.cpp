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
    int  levelorder(TreeNode* n)
    {
        if(n == nullptr)
            return 0;
        else
        {
            queue<TreeNode*> level;
            int sum = 0;
            int level_ = 1;
            int max_level = 1;
            level.push(n);
            
            while(level.size() != 0)
            {
                int temp_sum = 0;
                queue<TreeNode*> t_level;
                while(level.size() != 0)
                {
                    TreeNode* node = level.front();
                    level.pop();
                    
                    temp_sum += node->val;
                    if(node->left != nullptr)
                        t_level.push(node->left);
                    if(node->right != nullptr)
                        t_level.push(node->right);
                }
                
                if(sum < temp_sum){
                    max_level = level_;
                    sum = temp_sum;
                }
                level = t_level;
                level_++;
                
            }
            return max_level;
            
            
        }
    }
public:
    int maxLevelSum(TreeNode* root) 
    {
        return levelorder(root);   
    }
};
