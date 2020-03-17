class Solution {
private:
    
public:
    string frequencySort(string s) 
    {
        if(s.length() == 0 || s.length() == 1 || s.length() == 2)
            return s;
        
        vector<pair<int, int>> M;
        
        for(int i = 0; i < 128; i++)
        {
            pair<int, int>p;
            p.first = i;
            p.second = 0;
            M.push_back(p);
        }
        
        for(char x: s)
        {
            M[static_cast<int>(x)].second++;
        }
        
        sort(M.begin(), M.end(), [](const pair<int, int>& a, const pair<int, int>&b)
             {
                 return a.second > b.second;
             }
            );
        
        string result = "";
        
        
        for(int i = 0; i < M.size(); i++)
        {
            while(M[i].second > 0)
            {
                result += static_cast<char>(M[i].first);
                M[i].second--;
            }
        }
        
        return result;
        
        
    }
};
