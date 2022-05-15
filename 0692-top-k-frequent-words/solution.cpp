class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {

        unordered_map<string, int> wordCount;
        
        for(auto & word: words)
        {
            wordCount[word]++;
        }
        
        
        auto comp = [](pair<string, int> & a, pair<string, int> & b)
        {
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> Q(comp);
        
        for(auto & [word, freq]: wordCount)
        {
            Q.push({word, freq});
        }
        
        
        vector<string> topKWords;
        int numElements = 0;
        while(numElements < k)
        {
            topKWords.push_back(Q.top().first);
            Q.pop();
            numElements++;
        }
        
        return topKWords;
    }
};
