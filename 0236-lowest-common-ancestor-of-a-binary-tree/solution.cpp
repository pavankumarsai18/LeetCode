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
    bool search(TreeNode* root, TreeNode* target, vector<TreeNode*> & ancestors)
    {
        if(root == nullptr) return false;
        // cout<<"root "<<root->val<<endl;
        if(root == target)
        {
            ancestors.push_back(root);
            return true;
        }
        
        bool found = false;
        if(root->left != nullptr)
        {
            found = search(root->left, target, ancestors);
        }
        if(found == false && root->right != nullptr)
        {
            found = search(root->right, target, ancestors);
        }
        
        if(found){ancestors.push_back(root);}
        return found;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> pAncestors;
        vector<TreeNode*> qAncestors;
        
        // cout<<"p\n";
        search(root, p, pAncestors);
        
        // cout<<"q\n";
        search(root, q, qAncestors);
        
//         for(auto ancestor: pAncestors) cout<< ancestor->val<<" ";
//         cout<<endl;
//         for(auto ancestor: qAncestors) cout<<ancestor->val<<" ";
//         cout<<endl;
        
        int index1, index2;
        index1 = pAncestors.size()-1;
        index2 = qAncestors.size()-1;
        
        while(index1 >= 0 && index2 >= 0 && pAncestors[index1] == qAncestors[index2])
        {
            index1--; index2--;
        }
        
        

        
        return pAncestors[index1 + 1];
    }
};
