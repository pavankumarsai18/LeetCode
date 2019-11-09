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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root == nullptr)
            return vector<double>();
        
        queue<TreeNode*> lev;
        vector<double> result;
        lev.push(root);
        
        while(!lev.empty())
        {
            double count = 0;
            double sum = 0;
            int size = lev.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur_node = lev.front();
                sum += cur_node->val;
                count++;
                
                if(cur_node->left != nullptr || cur_node->right != nullptr)
                {
                    if(cur_node->left != nullptr)
                    {
                        lev.push(cur_node->left);
                       
                    }
                    if(cur_node->right != nullptr)
                    {
                        lev.push(cur_node->right);
        
                    }
                }
                lev.pop();
            }
            if(size > 0)
            {
                result.push_back(sum/count);
            }
        }
        return result;
        
    }
};
