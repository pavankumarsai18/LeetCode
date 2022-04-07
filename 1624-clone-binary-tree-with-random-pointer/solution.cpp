/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) 
    {   
        if(root == nullptr)
            return nullptr;
        unordered_map<Node*, NodeCopy*> nodeMap;
        stack<Node*> s;
        s.push(root);
        while(s.size())
        {
            Node* n = s.top();s.pop();
            nodeMap[n] = new NodeCopy(n->val, nullptr, nullptr, nullptr);
            if(n->left)
                s.push(n->left);
            if(n->right)
                s.push(n->right);
        }
        
        for(auto itr=nodeMap.begin();itr!=nodeMap.end();itr++)
        {
            Node* n = itr->first;
            NodeCopy* newNode = itr->second;
            if(n->left)
                newNode->left = nodeMap[n->left];
            if(n->right)
                newNode->right = nodeMap[n->right];
            if(n->random)
                newNode->random = nodeMap[n->random];
        }
        
        return nodeMap[root];
    }
};
