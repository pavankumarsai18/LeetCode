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
    int sumEvenGrandparent(TreeNode* root) {
        int result = 0;
        
        queue<TreeNode*> curLevel;
        curLevel.push(root);
        
        while(curLevel.size() != 0)
        {
            
            queue<TreeNode*> nextLevel; 
            while(curLevel.size() != 0)
            {
                TreeNode* curNode = curLevel.front();
                
                TreeNode* leftChild = curNode->left;
                TreeNode* rightChild = curNode->right;
                
                if(leftChild != nullptr)
                {
                        nextLevel.push(leftChild);
                }
                
                if(rightChild != nullptr)
                {
                    nextLevel.push(rightChild);
                }
                
                if((curNode->val)%2 == 0)
                {

                    if(leftChild != nullptr)
                    {
                        TreeNode* lgrandChild = leftChild->left;
                        TreeNode* rgrandChild = leftChild->right;
                        
                        if(lgrandChild != nullptr)
                            result += (lgrandChild)->val;
                        if(rgrandChild != nullptr)
                            result += (rgrandChild)->val;
                    }
                    
                    if(rightChild != nullptr)
                    {
                        
                        TreeNode* lgrandChild = rightChild->left;
                        TreeNode* rgrandChild = rightChild->right;
                        
                        if(lgrandChild != nullptr)
                            result += (lgrandChild)->val;
                        if(rgrandChild != nullptr)
                            result += (rgrandChild)->val;   
                    }
                    
                }
                
                curLevel.pop();
            }
            
            curLevel = nextLevel;
        }
        
        return result;
    }
};
