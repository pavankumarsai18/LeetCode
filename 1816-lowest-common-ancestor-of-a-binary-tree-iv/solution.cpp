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
public:
    void dfs(TreeNode* node, vector<TreeNode*> & path, unordered_set<TreeNode*>& nodeSet, vector<TreeNode*> & commonAncestors) 
    {
    
    if (node == nullptr || nodeSet.size() == 0) {
        return;
    }

    path.push_back(node);

    if (nodeSet.size() && nodeSet.find(node) != nodeSet.end()) {

        nodeSet.erase(node);
        if (commonAncestors.size() == 0) {
            commonAncestors = path;
        } else {
            // Find common Ancestors
            int index = 0;
            while (index < min(path.size(), commonAncestors.size())) {
                if (path[index] == commonAncestors[index]) {
                    ++index;
                } else {
                    break;
                }
            }

            commonAncestors = vector<TreeNode*>(commonAncestors.begin(), 
            commonAncestors.begin() + index);
        }
    }

    
    dfs(node->left, path, nodeSet, commonAncestors);
    dfs(node->right, path, nodeSet, commonAncestors);

    path.pop_back();

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> nodeSet(nodes.begin(), nodes.end());
        // unordered_map<TreeNode* , vector<TreeNode*>> nodeAncestorMap;

        vector<TreeNode*> path;
        vector<TreeNode*> commonAncestors;
        dfs(root, path, nodeSet, commonAncestors);

        return commonAncestors[commonAncestors.size() - 1];
    }
};
