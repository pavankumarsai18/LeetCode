class Solution {
public:
    vector<vector<int>> build_adj_list(vector<vector<int>>& edges) {
        int num_nodes = edges.size() + 1;
        vector<vector<int>> adj_list(num_nodes, vector<int>());

        for (auto & edge: edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        return adj_list;
    }

    pair<int, int> bfs(vector<vector<int>> & adj_list, int src) {
        int max_dist = -1, farthest = src;
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
                if (max_dist < dist) {
                    max_dist = dist;
                    farthest = node;
                }
                for (auto & neigh: adj_list[node]) {
                    if (seen.find(neigh) != seen.end()) {
                        continue;
                    }
                    Q.push(neigh);
                }
            }
            if (!Q.empty()) dist++;
        }
        return {farthest, dist};
    }

    int treeDiameter(vector<vector<int>>& edges) {
        auto adj_list = build_adj_list(edges);
        auto [farthest, _] = bfs(adj_list, 0);
        auto [_, diameter] = bfs(adj_list, farthest);
        return diameter;
    }
};
