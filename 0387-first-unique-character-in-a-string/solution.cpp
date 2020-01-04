class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, pair<int, int>> char_count;
        for(int i = 0; i < s.size(); i++)
        {
            auto itr = char_count.find(s[i]);
            if(itr == char_count.end())
            {
                char_count[s[i]] = pair<int, int>(1, i);
            }
            else
            {
                auto x = char_count[s[i]];
                char_count[s[i]] =  pair<int, int>(x.first+1, x.second);
            }
            
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            auto itr = char_count.find(s[i]);
            if(itr != char_count.end())
            {
                if(char_count[s[i]].first > 1)
                    char_count.erase(itr);
             }
        }

        if(char_count.size() == 0)
            return -1;
        
        
        int min = s.size();
        for(auto itr = char_count.begin(); itr != char_count.end(); itr++)
        {
            if(itr->second.second < min)
            {
                min = itr->second.second;
            }
        }
        return min;
       
        
        
    }
};
