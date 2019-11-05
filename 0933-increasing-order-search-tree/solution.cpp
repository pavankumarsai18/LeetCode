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
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root == nullptr)
            return nullptr;
        
        string result = inorder(root);
        //cout<<result;
        TreeNode* r = nullptr;
        TreeNode* curr = nullptr;
        for(int i = 0; i < result.size(); i++)
        {
            if(result[i] == ' ')
                ;
            
            
            else
            {
                string temp = "";
                while(result[i] != ' ')
                {
                    temp += result[i];


                    i++;
                }
                if(r == nullptr)
                {
                        r = new TreeNode(string_to_int(temp));
                        curr = r;
                }
                else
                {
                        curr->right = new TreeNode(string_to_int(temp));
                        curr = curr->right;
                }
                temp.clear();
            }
            
            
            
        }
        return r;
        
    }
    
    string inorder(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        string result = "";
        result += inorder(root->left);
        result += " ";
        result += std::to_string(root->val);
        result += " ";
        result += inorder(root->right);
        result += " ";
        return result;
    }
    
    int string_to_int(string & s)
    {
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            result += (static_cast<int>(s[i]) - 48);
            if(i != s.size() - 1)
                result *= 10;
        }
        return result;
    }
};
