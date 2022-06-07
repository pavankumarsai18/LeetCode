/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*> oldNode_newNode_map;
        unordered_set<Node*> visited;
        
        queue<Node*> Q;
        Q.push(node);
        visited.insert(node);
        while(Q.size() > 0)
        {
            Node* node = Q.front(); Q.pop();
            Node* newNode = new Node(node->val);
            
            oldNode_newNode_map[node] = newNode;
            
            for(Node* neighbor: node->neighbors)
            {
                if(visited.find(neighbor) == visited.end())
                {
                    Q.push(neighbor);
                    visited.insert(neighbor);
                }
            }   
        }        
        
        visited.clear();
        
        Q.push(node);
        visited.insert(node);
        
        while(Q.size() > 0)
        {
            Node* node = Q.front(); Q.pop();
            
            Node* new_node = oldNode_newNode_map[node];
            
            for(Node* neighbor: node->neighbors)
            {
                new_node->neighbors.push_back(oldNode_newNode_map[neighbor]);
                if(visited.find(neighbor) == visited.end())
                {
                    Q.push(neighbor);
                    visited.insert(neighbor);
                }
            }   
        }
        
        return oldNode_newNode_map[node];
        
        
    }
};
