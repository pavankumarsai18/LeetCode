class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        // just do a bfs or dfs

        queue<int> Q;
        unordered_set<int> visited;

        Q.push(source);

        unordered_map<int, vector<int>> adjList;

        for(vector<int> edge: edges)
        {
            if(adjList.find(edge[0]) == adjList.end())
                adjList[edge[0]] = vector<int>();
            if(adjList.find(edge[1]) == adjList.end())
                adjList[edge[1]] = vector<int>();

            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }


        while(Q.size())
        {
            int vertex = Q.front(); Q.pop();
            if(vertex == destination) return true;
            if(visited.find(vertex) != visited.end())
                continue;

            visited.insert(vertex);
            for(int adjVertex: adjList[vertex])
                Q.push(adjVertex);
        }

        return false;


    }
};
