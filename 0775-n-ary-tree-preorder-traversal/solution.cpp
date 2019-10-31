/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr)
            return vector<int>();
        
        vector<int> result;
        result.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++)
        {
            auto temp = preorder(root->children[i]);
            for(int j = 0; j < temp.size(); j++)
                result.push_back(temp[j]);
        }
        
        return result;
        
        
    }
};
