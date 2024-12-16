/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>  &parent_map) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            parent_map[root->left] = root;
            dfs(root->left, parent_map);
        }
        if (root->right) {
            parent_map[root->right] = root;
            dfs(root->right, parent_map);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        parent_map[root] = nullptr;
        dfs(root, parent_map);

        vector<int> ans;
        deque<TreeNode*> q;
        unordered_set<TreeNode*> seen;
        q.push_back(target);
        int distance = k;
        auto is_new = [&seen] (TreeNode* node) {
            return seen.find(node) == seen.end();
        };


        while (!q.empty() && distance > 0) {
            deque<TreeNode*> next_level;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop_front();
                if (node && is_new(node)) {
                    if (node->left && is_new(node->left)) {
                        next_level.push_back(node->left);
                    }
                    if (node->right && is_new(node->right)) {
                        next_level.push_back(node->right);
                    }

                    TreeNode* parent = parent_map[node];
                    if (parent && is_new(parent)) {
                        next_level.push_back(parent);
                    }
                }

                seen.insert(node);
            }
            distance--;
            q = std::move(next_level);

            // for (auto & node: q) {
            //     cout << node->val << " ";
            // }
            // cout << "\n";
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop_front();
        }
        return ans;


    }
};
