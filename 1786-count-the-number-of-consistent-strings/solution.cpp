class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        
        
        unordered_set<char> s;
        
        for(auto & c: allowed)
        {
            s.insert(c);
        }
        
        bool isAllowed = true;
        
        for(auto & word: words)
        {
            unordered_set<char> letters;
            for(auto & c: word)
            {
                auto itr = s.find(c);
                if(itr == s.end())
                {
                    isAllowed = false;
                }
            }
            
            if(isAllowed)
            {
                result++;
            }
            isAllowed = true;   
        }
        
        return result;
        
    }
};
