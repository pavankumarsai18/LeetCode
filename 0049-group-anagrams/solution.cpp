class Solution {
private:
    string Hash(string s)
    {
    
        string result = "";
        vector<int> R(26, 0);
        
        for(char c: s)
        {
            R[static_cast<int>(c) - 97]++;
        }
        
        
        for(auto i: R)
        {
            result += "#" + to_string(i);
        }
        
        return result;
        
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        
        unordered_map<string, vector<string>> M;
        
        for(int i = 0; i < strs.size(); i++)
        {
            string h = Hash(strs[i]);
            auto itr = M.find(h);
            if(itr == M.end())
            {
                vector<string> s= {strs[i]};
                M[h] = s;
            }
            else
            {
                M[h].push_back(strs[i]); 
            }
        }
        
        for(auto itr = M.begin(); itr != M.end(); itr++)
        {
            vector<string> s = itr->second;
            
            result.push_back(s);
        }
        
        
        return result;
        
        
    }
};
