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
    vector<TreeNode*> generateTrees(int n, int offset)
    {
        // cout<<"n "<<n<<" offset "<<offset<<endl;
        if(n == 0)
            return {nullptr};
        if(n == 1)
            return {new TreeNode(n+offset)};
       
        vector<TreeNode*> ans;
        for(int rootVal = 1; rootVal <= n; rootVal++)
        {
    
// cout<<"leftNodes "<<rootVal-1<<" rootVal "<<rootVal<<" rightNodes "<<n-rootVal<<" offset "<<offset<<endl;

            vector<TreeNode*> leftTrees  = generateTrees(rootVal-1, offset);
            vector<TreeNode*> rightTrees = generateTrees(n - rootVal, offset+rootVal); 
            
            for(auto  & leftTree: leftTrees)
            {
                for(auto & rightTree: rightTrees)
                {
                     TreeNode* newTree = new TreeNode(rootVal + offset);
                     newTree->left  = leftTree;
                     newTree->right = rightTree;
                    
                     ans.push_back(newTree);
                }
            }
        }
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        
        return generateTrees(n, 0);
    }
};
