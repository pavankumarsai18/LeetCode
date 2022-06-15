class Solution 
{
private:
    vector<int> score;
    vector<vector<int>> adjList;
    
public:
    int findLongestChain(int word)
    {
        if(score[word] != 0)
            return score[word];
        
        int curScore = 1;
        for(int neighbor: adjList[word])
        {
            curScore = max(curScore, findLongestChain(neighbor) +1);
        }
        score[word] = curScore;
        
        return curScore;
    }
    int longestStrChain(vector<string>& words) 
    {
        const int n = words.size();
        unordered_map<string, int> wordIndex;
        
        score = vector<int>(n, 0);
        adjList = vector<vector<int>>(n, vector<int>());
        
        for(int i = 0; i < n; i++)
        {
            wordIndex[words[i]] = i;
        }
        
        
        for(int i = 0; i < n; i++)
        {
            string word = words[i];
            
            const int wordLen = words[i].size();
            
            for(int removeIndex = 0; removeIndex < wordLen; removeIndex++)
            {
                string newWord = word.substr(0, removeIndex) + word.substr(removeIndex+1);
                    
                auto itr = wordIndex.find(newWord);
                if(itr != wordIndex.end())
                {
                    adjList[i].push_back(itr->second);
                }
            }
        }
        
        int ans = 0;
        for(int word = 0; word < n; word++)
        {
            ans = max(ans, findLongestChain(word));
        }
        
        return ans;
        
    }
};
