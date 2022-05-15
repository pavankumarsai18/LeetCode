class Solution {
public:
    string customSortString(string order, string s) 
    {
        unordered_map<char, int> orderMap;
        for(int i = 0; i < order.size(); i++)
        {
            orderMap[order[i]] = i;
        }
        
        
        vector<char> S;
        for(int i = 0; i < s.size(); i++)
        {
            S.push_back(s[i]);
        }
        
        
        sort(S.begin(),S.end(), [&orderMap](char & a, char & b)
        {
             
            return orderMap[a] < orderMap[b];
        });
        
        string result = "";
        for(int i = 0; i < S.size(); i++)
        {
            result += S[i];
        }
        
        return result;
        
    }
};
