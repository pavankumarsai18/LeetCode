/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    void preorder(TreeNode*& n)
    {
        if(n == nullptr)
        {
            return;
        }
        else
        {
            if(n->left != nullptr && n->right != nullptr)
            {
                n->left->val = (2*n->val) + 1;
                n->right->val = (2*n->val) + 2;
                preorder(n->left);
                preorder(n->right);
            }
            else if(n->left == nullptr && n->right != nullptr)
            {
                n->right->val = (2*n->val) + 2;
                preorder(n->right);
            }
            else if(n->left != nullptr && n->right == nullptr)
            {
                n->left->val = (2*n->val) + 1;
                preorder(n->left);
            }
            else
            {
                ;//do nothing
            }
        }
    }
    
    bool preorder_search(TreeNode* & n, const int& val)
    {
        if(n == nullptr)
        {
            return false;
        }
        else
        {
            if(n->val == val)
                return true;
            else
            {
                return preorder_search(n->left, val) || preorder_search(n->right, val);
            }
        }
    }
    
    TreeNode* Root = nullptr;
    unordered_map<int, bool> cache;
public:
    FindElements(TreeNode* root) {
        this->Root = root;
        if(Root == nullptr)
            ;
        else
        {
            Root->val = 0;
            preorder(Root);
        }
        
    }
    
    bool find(int target) {
        auto itr = this->cache.find(target);
        if(itr == this->cache.end())
        {
            this->cache[target] = preorder_search(this->Root, target);
            return this->cache[target];
        }
        else        
            return this->cache[target];
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
