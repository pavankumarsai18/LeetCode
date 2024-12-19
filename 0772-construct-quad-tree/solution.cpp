/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* construct_helper(const vector<vector<int>>& grid, const int & r, const int &c, const int &length) {
        if (length == 1) {
            return new Node(grid[r][c], true);
        }

        const int offset = length >> 1;

        array<Node*, 4> child_nodes = {
            construct_helper(grid, r, c, offset),
            construct_helper(grid, r, c + offset, offset),
            construct_helper(grid, r + offset, c, offset),
            construct_helper(grid, r + offset, c + offset, offset)
        };

        bool all_leaves = true;
        for (int i = 0; i < child_nodes.size(); ++i) {
            if (!child_nodes[i]->isLeaf) {
                all_leaves = false;
                break;
            }
        }

        bool all_same_val = true;
        bool value = child_nodes[0]->val;
        for (int i = 0; i < child_nodes.size(); ++i) {
            if (child_nodes[i]->val != child_nodes[0]->val) {
                all_same_val = false;
                break;
            }
        }

        if (all_leaves && all_same_val) {            
            for (int i = 0; i < child_nodes.size(); ++i) {
                delete child_nodes[i];
                child_nodes[i] = nullptr;
            }

            return new Node(value, true);
        }

        return new Node(false, false, child_nodes[0], child_nodes[1], child_nodes[2], child_nodes[3]);
    }

    Node* construct(vector<vector<int>>& grid) {
        const int n = grid.size();
        return construct_helper(grid, 0, 0, n);
    }
};
