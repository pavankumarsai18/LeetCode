class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        const int n = s.size();
        unordered_map<char, char> STmap;
        unordered_map<char, char> TSmap;

        for(int i = 0; i < n; i++)
        {
            if(STmap.find(s[i]) == STmap.end() && TSmap.find(t[i]) == TSmap.end())
            {
                STmap[s[i]] = t[i];
                TSmap[t[i]] = s[i];
            }
            else if(STmap[s[i]] != t[i] || TSmap[t[i]] != s[i]) return false;
        }
        return true;
    }
};
