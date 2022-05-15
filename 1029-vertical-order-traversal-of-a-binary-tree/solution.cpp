/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preOrderTraversal(TreeNode* node, int depth, int vertLevel, unordered_map<TreeNode*, pair<int, int>> & nodePosMap, int & leftMost, int & rightMost)
    {
        
        if(node == nullptr)
            return;
        
        leftMost = min(leftMost, vertLevel);
        rightMost = max(rightMost, vertLevel);
        
        nodePosMap[node] = {depth, vertLevel};
        
        preOrderTraversal(node->left, depth+1, vertLevel-1, nodePosMap, leftMost, rightMost);
        preOrderTraversal(node->right, depth+1, vertLevel+1, nodePosMap, leftMost, rightMost);
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        
        int leftMost, rightMost;
        leftMost = rightMost = 0;
        
        unordered_map<TreeNode*, pair<int,int>> nodePosMap;
        
        
        preOrderTraversal(root, 0, 0, nodePosMap, leftMost, rightMost);
        
        
        unordered_map<int, vector<pair<int, int>>> vertLevelNodes;
        
        for(auto & [node, pos]: nodePosMap)
        {
            int vertLevel, depth;
            depth = pos.first; vertLevel = pos.second;
            
            if(vertLevelNodes.find(vertLevel) == vertLevelNodes.end())
            {
                vertLevelNodes[vertLevel] = vector<pair<int, int>>();
            }
            
            vertLevelNodes[vertLevel].push_back({node->val, depth});
        }
        
        vector<vector<int>> result;
        
        auto comp = [](pair<int, int> & a, pair<int, int> & b)
        {
             int depth1, val1;
             int depth2, val2;
            
            depth1 = a.second; val1 = a.first;
            depth2 = b.second; val2 = b.first;
            
            if(depth1 == depth2)
            {
                return val1 < val2;
            }
            return depth1 < depth2;
        };
        
        for(int vertLevel = leftMost; vertLevel <= rightMost; vertLevel++)
        {
            if(vertLevelNodes.find(vertLevel) != vertLevelNodes.end())
            {
                
                vector<int> columnNodes;
                
                auto nodes = vertLevelNodes[vertLevel];
                sort(nodes.begin(), nodes.end(), comp);
                
                for(auto & node: nodes)
                {
                    columnNodes.push_back(node.first);
                }
                
                result.push_back(columnNodes);
            }
        }
        
        return result;
        
    }
};
