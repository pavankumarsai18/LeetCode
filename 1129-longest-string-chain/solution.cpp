class Solution 
{
private:
    vector<vector<int>> edges;
    vector<int> score;
    
    int findLongestChain(int word)
    {
        if(score[word] != 0)
            return score[word];
        score[word] = 1;
        for(int neighbor: edges[word])
        {
            score[word] = max(score[word], findLongestChain(neighbor) + 1);
        }
        
        return score[word];
    }
public:
    int longestStrChain(vector<string>& words) 
    {   
        const int n = words.size();
        unordered_map<string, int> word_map;
        
        edges.clear();
        score.clear();
        
        score = vector<int>(n, 0);
        edges = vector<vector<int>>(n, vector<int>());
        
        for(int i = 0; i < n; i++)
        {
            word_map[words[i]] = i;
        }
        
        for(int i = 0; i <n; i++)
        {    
            string s = words[i];
            for(int j = 0; j < s.size(); j++)
            {
                string newWord = s.substr(0, j) + s.substr(j+1);
                auto itr = word_map.find(newWord);
                if(itr == word_map.end())
                    continue;
                
                edges[i].push_back(word_map[newWord]);
            }
        }
        
        int ans = 0;
        for(int word = 0; word < n; word++)
        {
            ans = max(ans,findLongestChain(word));
        }
        
        return ans;
    }
};
