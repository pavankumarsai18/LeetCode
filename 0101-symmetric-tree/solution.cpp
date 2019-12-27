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
    void Invert(TreeNode* & n)
    {
        if(n == nullptr )
            return;
        else
        {
            // if(n->left != nullptr && n->right != nullptr)
            // {
                std::swap(n->left,n->right);
            // }
//             else if(n->left != nullptr && n->right == nullptr)
//             {
                
//                 n->right = n->left;
//                 n->left = nullptr;
//             }
//             else if(n->right != nullptr && n->left == nullptr)
//             {
               
//                 n->left = n->right;
//                 n->right = nullptr;
//             }
//             else
//             {
//                 ;
//             }
        }
    }
    void preorder_inv(TreeNode* &A)
    {
        if(A == nullptr)
            return;
        else
        {
            swap(A->left, A->right);
            preorder_inv(A->left);
            preorder_inv(A->right);
            
            
        }
    }
    
    bool compare(TreeNode* & A, TreeNode* & B)
    {
        queue<TreeNode*> q_a;
        queue<TreeNode*> q_b;
        
        q_a.push(A);
        q_b.push(B);
        while(q_a.size() != 0 && q_b.size() != 0)
        {
            auto temp_a = q_a;
            while(temp_a.size())
            {
                auto x = temp_a.front();
                if(x != nullptr)
                    cout<<x->val<<" ";
                else
                    cout<<0<<" ";
                temp_a.pop();
            }
            cout<<endl;
            auto temp_b = q_b;
            while(temp_b.size())
            {
                auto x = temp_b.front();
                if(x != nullptr)
                    cout<<x->val<<" ";
                else
                    cout<<0<<" ";
                temp_b.pop();
            }
            cout<<endl;
            if(q_a.front() != nullptr && q_b.front()!=nullptr)
            {
                if(q_a.front()->val != q_b.front()->val)
                {
                    cout<<"val s are not equal\n";
                    return false;
                }
                else
                {
                    auto temp = q_a.front();
                    auto temp_ = q_b.front();

                    q_a.push(temp->left);
                    q_a.push(temp->right);
                    q_a.pop();

                    q_b.push(temp_->left);
                    q_b.push(temp_->right);
                    q_b.pop();

                }
            }
            else if(q_a.front() == nullptr && q_b.front() == nullptr)
            {
                q_a.pop();
                q_b.pop();
            }
            else
            {
                return false;
            }
        }
        
        if(q_a.size() != q_b.size())
            return false;
        return true;
    
    }
    
    void print(TreeNode* root)
    {
        // if(root == nullptr)
        // {
        //     cout<<"Null ";
        // }
        if(root != nullptr)
        {
           cout<<root->val<<" ";
            
            print(root->left);
            print(root->right);
        }
        else
        {cout<<0<<" ";}
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(root == nullptr)
            return true;
        // True if the left subtree
        // is same as the right subtree
        print(root);
        //Invert(root->right);
        preorder_inv(root->right);
        cout<<endl;
        print(root);
        return compare(root->right, root->left);
        // return true;
    }
    

};
