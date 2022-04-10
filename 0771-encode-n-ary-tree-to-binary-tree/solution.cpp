/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) 
    {
        if(root == nullptr)
            return nullptr;
        TreeNode* result = new TreeNode(root->val);
        if(root->children.size() > 0)
        {
            Node* left = root->children[0];
            result->left = encode(left);
        }
        TreeNode* cur = result->left;
        for(int i = 1; i < root->children.size();i++)
        {
            Node* right = root->children[i];
            cur->right = encode(right);
            cur = cur->right;
        }
        return result;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) 
    {
        if(root == nullptr)
            return nullptr;
        
        Node* result = new Node(root->val, vector<Node*>());
        TreeNode* cur = root->left;
        while(cur)
        {
            result->children.push_back(decode(cur));
            cur = cur->right;
        }
        return result;
      
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
