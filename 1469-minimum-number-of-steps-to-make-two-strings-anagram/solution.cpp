class Solution {
public:
    int minSteps(string s, string t)
    {
        if(s.size() != t.size())
            return -1;
        if(s.size() == 0)
            return 0;
        
        unordered_map<char, int> S_char_count;
        unordered_map<char, int> T_char_count;
        
        for(char c: s)
        {
            auto itr = S_char_count.find(c);
            if(itr == S_char_count.end())
            {
                S_char_count[c] = 1;
            }
            else
            {
                S_char_count[c]++;
            }
        }
        
        for(char c: t)
        {
            auto itr = T_char_count.find(c);
            if(itr == T_char_count.end())
            {
                T_char_count[c] = 1;
            }
            else
            {
                T_char_count[c]++;
            }
        }
        // t --> s
        // s
        int mismatch = 0;
        for(auto itr = S_char_count.begin(); itr != S_char_count.end(); itr++)
        {
            if(itr->second > T_char_count[itr->first])
                mismatch += itr->second - T_char_count[itr->first];
        }

        return mismatch;
        
        
        
        
    }
};
