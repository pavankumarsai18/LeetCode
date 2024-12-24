class Solution {
public:
    vector<vector<int>> build_adj_list(vector<vector<int>> & edges) {
        int num_nodes = edges.size() + 1;
        vector<vector<int>> adj_list(num_nodes, vector<int>());
        for (auto & edge: edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        return adj_list;
    }

    pair<int, int> bfs(vector<vector<int>> & tree, int src) {
        int diameter_node = src, max_dist = -1;
        unordered_set<int> seen;
        queue<int> Q;
        Q.push(src);
        int dist = 0;
        while (!Q.empty()) {
            int cur_size = Q.size();
            for (int i = 0; i < cur_size; ++i) {
                int node = Q.front();
                Q.pop();

                if (seen.find(node) != seen.end()) {
                    continue;
                }
        
                seen.insert(node);
                if (dist > max_dist) {
                    max_dist = dist;
                    diameter_node = node;
                }

                for (auto & neigh: tree[node]) {
                    if (seen.find(neigh) != seen.end()) {
                        continue;
                    }
                    Q.push(neigh);
                }
            }
            dist++;

        }

        return {diameter_node, max_dist};
    }


    int get_diameter(vector<vector<int>> & tree) {
        auto [farthest_node, _] = bfs(tree, 0);
        auto [_, diameter] = bfs(tree, farthest_node);
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> tree1 = build_adj_list(edges1);
        vector<vector<int>> tree2 = build_adj_list(edges2);

        int tree1_diameter = get_diameter(tree1);
        int tree2_diameter = get_diameter(tree2);

        int merged_diameter = ceil(tree1_diameter/2.0) + ceil(tree2_diameter/2.0) + 1;

        return max({tree1_diameter, tree2_diameter, merged_diameter});
    }
};
