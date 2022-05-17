/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<TreeNode*> curLevel;
        curLevel.push_back(root);
        
        vector<int> result;
        
        while(curLevel.size())
        {
            TreeNode* rightMostNode = curLevel[curLevel.size() - 1];
            if(rightMostNode)
                result.push_back(rightMostNode->val);
            
            vector<TreeNode*> nextLevel;
            
            for(int i = 0; i < curLevel.size(); i++)
            {
                TreeNode* curNode = curLevel[i];
                if(curNode && curNode->left != nullptr)
                {
                    nextLevel.push_back(curNode->left);
                }
                if(curNode && curNode->right != nullptr)
                {
                    nextLevel.push_back(curNode->right);
                }
            }
            
            curLevel = nextLevel;

            // for(auto & node: curLevel)
            // {   if(node == nullptr)
            //         cout<<"null ";
            //     else
            //         cout<<node->val<<" ";
            // }
            // cout<<endl;
            
        }
        
        return result;
        
    }
};
