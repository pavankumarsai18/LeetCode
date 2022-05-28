class Solution {
public:
    void getCharCount(string & s, unordered_map<char, int> & charCount)
    {
        charCount = unordered_map<char, int>();
        for(int i = 0; i < s.size(); i++)
        {
            charCount[s[i]]++;
        }
        return;
    }
    bool isAnagram(unordered_map<char, int> & curCount, unordered_map<char, int> & prevCount)
    {   
        if(prevCount.size() != curCount.size())
            return false;
        
        for(auto & [c, count]: curCount)
        {
            if(prevCount.find(c) == prevCount.end() || prevCount[c] != count)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) 
    {
        vector<string> result;
        
        unordered_map<char, int> curCount;
        unordered_map<char, int> prevCount;

        getCharCount(words[0], prevCount);
        
        result.push_back(words[0]);
        int prevIndex = 0;
        
        for(int curIndex = 1; curIndex < words.size(); curIndex++)
        {
            getCharCount(words[curIndex], curCount);
            
            if(!isAnagram(curCount,prevCount))
            {
                result.push_back(words[curIndex]);
                prevIndex = curIndex;   
            }
            
            prevCount = curCount;
        }
        
        return result;
        
        
    }
};
