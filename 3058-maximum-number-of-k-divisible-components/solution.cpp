class Solution {
public:
    int dfs(int parent, int node, vector<vector<int>> & adjList, vector<int>& nodeValues, int k, int & num_components) {
        int sum = 0;
        for (auto neigh: adjList[node]) {
            if (neigh != parent) {
                sum += dfs(node, neigh, adjList, nodeValues, k, num_components);
                sum %= k;
            }
        }

        sum += nodeValues[node];
        sum %= k;

        if (sum == 0) {
            num_components++;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n, vector<int>());
        for(auto & edge: edges) {
            int n1 = edge[0], n2 = edge[1];
            adjList[n1].push_back(n2);
            adjList[n2].push_back(n1);
        }

        int num_components = 0;
        dfs(-1, 0, adjList, values, k, num_components);
        return num_components;
    }
};
