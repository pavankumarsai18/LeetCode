class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        // create a dag and find sink
        // find the smallest lexicographic string
        const int numWords = words.size();
        unordered_map<string, int> stringIndex;
        
        for(int i = 0; i < numWords; i++)
        {
            stringIndex[words[i]] = i;
        }
        
        vector<vector<int>> adjList(numWords, vector<int>());
        vector<bool> isSource(numWords, true);
        vector<int> depth(numWords, 0);
        for(int i = 0; i < numWords; i++)
        {
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                auto itr = stringIndex.find(words[i] + ch);
                
                if(itr != stringIndex.end())
                {
                    adjList[i].push_back(itr->second);
                    isSource[itr->second] = false;
                    
                }
            }
        }
        
        // Now that we have the aj matrix
        // do a dfs traversal and assign each "word" a depth and chose the sinks
        // that were visited, among the sinks chose the one with largest length and 
        // smallest lexico graphic order
        vector<int> sinks;
        for(int i = 0; i < numWords; i++)
        {
            if(isSource[i] && words[i].size() == 1)
            {
                // dfs
                queue<int> Q;
                Q.push(i);
                depth[i] = 0;
                while(!Q.empty())
                {
                    int cur = Q.front(); Q.pop();
                    
                    if(adjList[cur].empty()) sinks.push_back(cur);
                    
                    for(int & neigh: adjList[cur])
                    {
                        depth[neigh] = depth[cur] + 1;
                        Q.push(neigh);
                    }
                }
            }
        }   
        
        
        // Get the one with highest depth
        string ans = "";
        int curDepth = 0;
        for(int & sink: sinks)
        {
            if(depth[sink] >= curDepth && (ans.size() < words[sink].size() || (ans.size() == words[sink].size() && ans > words[sink])))
            {
                ans = words[sink];
            }
            
        }
        
        return ans;
        
    }
};
