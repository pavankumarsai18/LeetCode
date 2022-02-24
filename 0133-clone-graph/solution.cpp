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
            
        // TWO pass algorithm
        unordered_map<Node*, Node*> cloneMap;
        
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(node);
        
        while(q.size())
        {
            Node* n = q.front();
            q.pop();
            auto found = visited.find(n);
            if(found == visited.end())
            {
                visited.insert(n);
                Node* clone = new Node(n->val);
                cloneMap[n] = clone;
                
                for(int i = 0; i < n->neighbors.size(); i++)
                {
                    q.push(n->neighbors[i]);
                }
            }
            
        }
        
        Node* result = cloneMap[node];
        
        for(auto itr = cloneMap.begin(); itr != cloneMap.end(); itr++)
        {
            Node* clonedNode = itr->second;
            Node* node = itr->first;
            
            clonedNode->neighbors = vector<Node*>();
            for(int i = 0; i < node->neighbors.size();)
            {
                clonedNode->neighbors.push_back(cloneMap[node->neighbors[i++]]);
            }
        }
    
        return result;
    }
};
