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
    string tree2str(TreeNode* t) 
    {    
        if(t == nullptr)
            return "";
        //perform a preorder traversal
        string result = "";
        stringstream ss;
        ss << t->val;
        ss >> result;
        if(t->left != nullptr)
        {
            result += "(";
            preorder(t->left, result);
            if(t->right != nullptr)
            {
                result += ")(";
                preorder(t->right, result);
                result += ")";
            }
            else
                result += ")";
        }
        else
        {
            
            if(t->right != nullptr)
            {
                result += "()(";
                preorder(t->right, result);
                result += ")";
            }
        }
        return result;
        
    }
    
    void preorder(TreeNode*t, string & s)
    {
        if(t == nullptr)
            return;
        else
        {
            stringstream ss;
            if(t->left == nullptr && t->right == nullptr)
            {
                ss << t->val;
                string temp = "";
                ss >> temp;
                s += temp;
            }
            else if(t->left == nullptr && t->right != nullptr)
            {
                ss << t->val;
                string temp = "";
                ss >> temp;

                s += temp;
                s += "()";
                
                s += "(";
                preorder(t->right, s);
                s += ")";
            }
            else if(t->right == nullptr && t->left != nullptr)
            {
                ss << t->val;
                string temp = "";
                ss >> temp;
                

                s += temp;
 
                s += "(";
                preorder(t->left,s);
                s += ")";
                
            }
            else
            {
                ss << t->val;
                string temp = "";
                ss >> temp;
                s += temp;
                s += "(";
                preorder(t->left, s);
                s += ")(";
                preorder(t->right, s);
                s += ")";
                
            }
        }
    }
};
