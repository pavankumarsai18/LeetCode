class WordDistance {
private:
    unordered_map<string, vector<int>> wordMap;
public:
    WordDistance(vector<string>& wordsDict) 
    {
        for(int i = 0; i < wordsDict.size(); i++)
        {
            wordMap[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2)
    {
        vector<int> & indices1 = wordMap[word1];
        vector<int> & indices2 = wordMap[word2];
        
        int ind1, ind2; ind1 = ind2 = 0;
        int minDiff = INT_MAX;
        
        while(ind1 < indices1.size() && ind2 < indices2.size())
        {
            minDiff = min(minDiff, abs(indices1[ind1] - indices2[ind2]));
            
            if(indices1[ind1] < indices2[ind2]) ind1++;
            else ind2++;
        }
        
        return minDiff;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
