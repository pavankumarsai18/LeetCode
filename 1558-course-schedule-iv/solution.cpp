class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj_list;
        vector<int> indegree(numCourses, 0);
        for (auto & edge: prerequisites) {
            int start = edge[0], end = edge[1];
            indegree[end]++;
            if (adj_list.find(start) == adj_list.end()) {
                adj_list[start] = {};
            }
            adj_list[start].push_back(end);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adj_list[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }

                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> answer;
        for (auto q: queries) {
            answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
        }

        return answer;

    
    }
};
