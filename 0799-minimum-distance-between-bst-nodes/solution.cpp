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
private:
    void postOrder(TreeNode* root, vector<int>& V)
    {
        if(root == nullptr)
        {
            return;
        }
        else{
            if(root->left != nullptr)
            {
                postOrder(root->left, V);
            }
            V.push_back(root->val);
            if(root->right !=nullptr)
            {
                postOrder(root->right, V);
            }
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        // L M R 
        vector<int> Tree;
        
        postOrder(root, Tree);
        
        sort(Tree.begin(), Tree.end());
        
        int min_difference = -1;
        if(Tree.size() == 0)
        {
            return 0;
        }
        if(Tree.size() == 1)
        {
            return Tree[0];
        }
        
        for(int i = 0; i < Tree.size() - 1; i++)
        {
            int diff = Tree[i + 1] - Tree[i];
            
            if(min_difference == -1)
            {
                min_difference = diff;
            }
            else if(min_difference > diff)
            {
                min_difference = diff;
            }
        }
        
        return min_difference;

    }
};
