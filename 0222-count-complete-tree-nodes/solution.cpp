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
    int getDepth(TreeNode* root)
    {
        int depth = 0;
        while(root->left != nullptr)
        {
            depth++;
            root = root->left;
        }
        
        return depth;
    }
    
    bool exists(int depth, TreeNode* root, int index)
    {
        int left  = 0;
        int right = pow(2, depth) - 1;
        
        for(int iter = 0; iter < depth; iter++)
        {
            int mid = left + (right - left)/2;
            
            if(index <= mid)
            {
                root = root->left;
                right = mid;
            }
            else
            {
                root = root->right;
                left = mid + 1;
            }            
        }
    
        return (root != nullptr);
    }
    
public:
    int countNodes(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        
        int depth = getDepth(root);
        if(depth == 0) return 1;
        
        int left  = 1;
        int right = pow(2, depth) - 1;
        
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(exists(depth, root, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return pow(2, depth) - 1 + left;
        
        
    }
};
