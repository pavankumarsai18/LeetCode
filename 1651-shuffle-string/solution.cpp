class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string result = s;
        int i = 0;
        for(auto & index: indices)
        {
            result[index] = s[i];
            i++;
        }
        
        return result;
    }
};
