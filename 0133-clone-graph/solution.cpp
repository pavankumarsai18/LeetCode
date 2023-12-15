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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // clone nodes and store in hash map
        unordered_map<Node*, Node*> oldNode_newNode_map;

        queue<Node*> Q;
        unordered_set<Node*>visited;

        Q.push(node);
        visited.insert(node);

        while (Q.size()) {

            Node* oldNode = Q.front(); Q.pop();
            Node* newNode = new Node(oldNode->val);

            oldNode_newNode_map[oldNode] = newNode;

            for (auto & neigh: oldNode->neighbors) {
                bool notSeen = (visited.find(neigh) == visited.end());
                if (notSeen) {
                    Q.push(neigh);
                    visited.insert(neigh);
                }
            }
        }

        // run bfs
        visited.clear();
        Q = queue<Node*>();

        Q.push(node);
        visited.insert(node);
        while (Q.size()) {

            Node* oldNode = Q.front(); Q.pop();

            Node* newNode = oldNode_newNode_map[oldNode];
            for (auto & neigh: oldNode->neighbors) {
                newNode->neighbors.push_back(oldNode_newNode_map[neigh]);

                bool notSeen = (visited.find(neigh) == visited.end());
                if (notSeen) {
                    Q.push(neigh);
                    visited.insert(neigh);
                }
            }
        }

        return oldNode_newNode_map[node];


        
    }
};
