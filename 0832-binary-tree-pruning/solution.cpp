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
    void prune(TreeNode* node, int & numOnes)
    {
        if(node == nullptr) return;
        int numOnesLeft, numOnesRight;
        numOnesLeft = numOnesRight = 0;

        if(node->left)
        {
            prune(node->left, numOnesLeft);
            
            if(numOnesLeft == 0)
            {
                node->left = nullptr;
            }
        }
        
        if(node->right)
        {
            prune(node->right, numOnesRight);
            
            if(numOnesRight == 0)
            {
                node->right = 0;
            }
        }
        
        if(node->val == 1)
            numOnes++;
        
        numOnes += numOnesLeft;
        numOnes += numOnesRight;
        
        return;
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        TreeNode * dummy = new TreeNode(1, root, nullptr);
        int numOnes = 0;
        prune(dummy, numOnes);
        
        return dummy->left;
        
    }
};
