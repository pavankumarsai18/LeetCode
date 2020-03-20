class Solution {
private:
    vector<vector<int>> findPaths(vector<vector<int>>& graph, int vertex)
    {
        if(vertex == graph.size() - 1)
        {
            vector<vector<int>> result;
            vector<int> p = {vertex};
            result.push_back(p);
            return result;
        }
        
        vector<vector<int>> result;
        
        for(int v: graph[vertex])
        {
            auto R = findPaths(graph, v);
            for(auto &p: R)
            {
                vector<int> path = {vertex};
                for(auto & ver: p)
                {
                    path.push_back(ver);
                }
                result.push_back(path);
            }
        }
        
        return result;
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        
        int start = 0;
        int end = graph.size() - 1;
        vector<vector<int>> R = findPaths(graph, 0);
        // vector<vector<int>> result;
        // for(auto path: R)
        // {
        //     if(path[path.size() - 1] == end)
        //     {
        //         result.push_back(path);
        //     }
        // }
        return R;

        
    }
};
