class Solution {
private:
    bool checkSubstring(string & pattern, string & word)
    {
        if(pattern.size() > word.size())
            return false;
        
        if(pattern.size() == word.size())
            return pattern == word;
        
        
        for(int i = 0; i <= word.size() - pattern.size(); i++)
        {
            string substring = word.substr(i, pattern.size());
            if(substring == pattern)
                return true;
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) 
    {
        unordered_map<string, bool> M;
        int result = 0;
        for(auto & pattern: patterns)
        {
            auto itr = M.find(pattern);
            if(itr != M.end())
            {
                if(itr->second)
                    result += 1;
            }
            else
            {
                M[pattern] = checkSubstring(pattern, word);
                            
                if(M[pattern])
                    result += 1;
            }
        }
        
        return result;
    }
};
