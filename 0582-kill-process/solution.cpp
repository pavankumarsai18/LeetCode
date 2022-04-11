class Solution {
private:
    void dfs(unordered_map<int, vector<int>> & tree, int node, unordered_set<int>& visited)
    {
        visited.insert(node);
        for(auto & child: tree[node])
        {
            dfs(tree, child, visited);
        }
        return;
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) 
    {
        unordered_map<int, vector<int>> tree;
        for(int i = 0; i < ppid.size(); i++)
        {
            if(tree.find(ppid[i]) == tree.end())
            {
                tree[ppid[i]] = vector<int>();
            }
            tree[ppid[i]].push_back(pid[i]);
        }
        
        unordered_set<int> visited;
        dfs(tree, kill, visited);
        vector<int> result;
        for(auto & node: visited)
            result.push_back(node);
        return result;
        
    }
};
