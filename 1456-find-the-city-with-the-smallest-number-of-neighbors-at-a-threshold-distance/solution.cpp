class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distanceMatrix(n, vector<int>(n, 1e9 + 7));
        for (int i = 0; i < n; ++i) {
            distanceMatrix[i][i] = 0;
        }
        
        for (const auto & edge: edges) {
            int source = edge[0];
            int dest = edge[1];
            int weight = edge[2];

            distanceMatrix[source][dest] = weight;
            distanceMatrix[dest][source] = weight;

        }

        for (int k = 0; k < n; k++) {
            for (int j =  0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    distanceMatrix[i][j] = min(distanceMatrix[i][j],
                    distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }
        int min_reachable_nodes = n, max_vertex = -1;

        for (int i = 0; i < n; ++i) {
            int num_reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    num_reachable++;
                }
            }

            if (num_reachable <= min_reachable_nodes) {
                min_reachable_nodes = num_reachable;
                max_vertex = i;
            }
        }

        return max_vertex;
    }
};
