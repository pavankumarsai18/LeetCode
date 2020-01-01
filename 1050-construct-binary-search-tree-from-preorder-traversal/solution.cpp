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
    void partition(vector<int>& preorder, int root_index,int end_index, int& left_index, int& gr_index )
    {
        // cout<<"root index "<<root_index<<" end_index "<<end_index<<endl;
        
        if(root_index + 1 <= end_index && preorder[root_index + 1] < preorder[root_index])
        {
            left_index = root_index + 1;
        }
        else
        {
            left_index = -1;
        }
        int r_child = root_index;
        if(root_index + 1 > end_index)
            gr_index = -1;
        else
        {
            while(r_child < end_index && preorder[r_child] <= preorder[root_index])
            {
                r_child++;
            }
            if(r_child > end_index)
                gr_index = -1;
            
            else
            {
                if(preorder[r_child] < preorder[root_index])
                    gr_index = -1;
                else
                    gr_index = r_child;
            }
        }
        
        return;
    }
    
    
    TreeNode* create_tree(vector<int>& preorder, int root_index, int end_index)
    {
        // cout<<preorder[root_index]<<endl;
        TreeNode* node;
        node = new TreeNode(preorder[root_index]);

        int left_child = -1;
        int right_child = -1;
        partition(preorder, root_index, end_index, left_child, right_child);
        
        // cout<<"left_child "<<left_child<<" right_child "<<right_child<<endl;
        
        if(left_child == -1)
            node->left = nullptr;
        else
        {
            if(right_child != -1)
            {
                int temp_left = left_child;
                int temp_right = right_child;
                node->left = create_tree(preorder, temp_left, temp_right - 1);
            }
            else
            {
                int temp_left = left_child;
                int temp_right = right_child;
                node->left = create_tree(preorder, temp_left, end_index);
            }
        }
        
        if(right_child == -1)
            node->right = nullptr;
        else
        {
            int temp_left = left_child;
            int temp_right = right_child;
            node->right = create_tree(preorder, temp_right, end_index);
        }
        
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        if(preorder.size() == 0)
            return nullptr;
        TreeNode* Tree =  create_tree(preorder, 0, preorder.size() - 1);

        return Tree;
        
    }
    
    
};
