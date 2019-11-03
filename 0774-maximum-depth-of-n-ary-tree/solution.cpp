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
    int maxDepth(Node* root) 
    {
        return maxDepthNode(root);
    }
    
    int maxDepthNode(Node * n)
    {
        if(n == nullptr)
            return 0;
        else
        {
            int result = 1;
            
            for(int i = 0; i < n->children.size(); i++)
            {
                int val = maxDepthNode(n->children[i]) + 1;
                if(result < val)
                    result = val;
            }
            
            return result;
        }
    }
};
