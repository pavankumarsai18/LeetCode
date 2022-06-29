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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr ^ q == nullptr)
        {
            return false;
        }

        stack<TreeNode*> PStack;
        stack<TreeNode*> QStack;

        PStack.push(p);
        QStack.push(q);

        while(PStack.size() && QStack.size())
        {
            TreeNode* curP = PStack.top(); PStack.pop();
            TreeNode* curQ = QStack.top(); QStack.pop();

            if((!curP && !curQ) || (curP && curQ && curP->val == curQ->val))
            {
                if(curP && curQ)
                {
                    PStack.push(curP->right);
                    PStack.push(curP->left);
                    QStack.push(curQ->right);
                    QStack.push(curQ->left);
                }
            }
            else
            {
                return false;
            }
        }
        if(PStack.empty() && QStack.empty())
            return true;
        return false;


        
    }
};
