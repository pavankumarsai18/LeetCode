class Solution {
public:
    string greatestLetter(string s) 
    {
        vector<bool> lowercase(26);
        vector<bool> uppercase(26);
        for(auto ch: s)
        {
            if(ch - 'a' >= 0 && ch - 'a' <= 26)
            {
                lowercase[ch-'a'] = true;
            }
            else
            {
                uppercase[ch-'A'] = true;
            }
        }
        
        for(int i = 25; i >= 0; i--)
        {
            if(lowercase[i] && uppercase[i])
            {
                return string(1,i + 'A');
            }
        }
        return "";
        
    }
};
