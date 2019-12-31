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
private:
    void inorder(TreeNode* n, vector<int>& elements)
    {
        if(n == nullptr)
            return;
        else
        {
            if(n->left != nullptr && n->right != nullptr)
            {
                inorder(n->left, elements);
                elements.push_back(n->val);
                inorder(n->right, elements);
            }
            else if(n->left == nullptr && n->right != nullptr)
            {
                elements.push_back(n->val);
                inorder(n->right, elements);
            }
            else if(n->left != nullptr && n->right  == nullptr)
            {
                inorder(n->left, elements);
                elements.push_back(n->val);
            }
            else
            {
                elements.push_back(n->val);
            }
        }
        
    }
    
    vector<int> merge(vector<int>& a, vector<int>& b)
    {
        int i_a, i_b;
        i_a = i_b = 0;
        vector<int> result;
        while(i_a != a.size() && i_b != b.size())
        {
            if(a[i_a] <= b[i_b])
            {
                result.push_back(a[i_a]);
                i_a ++;
            }
            else
            {
                result.push_back(b[i_b]);
                i_b ++;
            }
        }
        
        
        if(i_a != a.size())
        {
            while(i_a != a.size())
            {
                result.push_back(a[i_a]);
                i_a++;
            }
        }
        else if(i_b != b.size())
        {
            while(i_b != b.size())
            {
                result.push_back(b[i_b]);
                i_b++;
            }
        }
    
        return result;
    }
public:
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    
        // Since it is a BST we can perform a inorder traversal and
        // merge the two vectors
        
        vector<int> list_1;
        vector<int> list_2;
    
        
        
        inorder(root1, list_1);
        inorder(root2, list_2);
        
        
        // for(int i = 0; i < list_1.size(); i++)
        // {
        //     cout<<list_1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < list_2.size(); i++)
        // {
        //     cout<<list_2[i]<<" ";
        // }
        
        // Merge
        return merge(list_1, list_2);
    }
};
