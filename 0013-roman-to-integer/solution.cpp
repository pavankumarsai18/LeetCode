class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> Table;
        
        Table['I'] = 1;
        Table['V'] = 5;
        Table['X'] = 10;
        Table['L'] = 50;
        Table['C'] = 100;
        Table['D'] = 500;
        Table['M'] = 1000;
        
        int result = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(i+1 < s.size() && Table[s[i]] < Table[s[i+1]])
            {
                result += (Table[s[i+1]] - Table[s[i]]);
                i++;
            }
            else
            {
                result += Table[s[i]];
            }
        }
        return result;
        
    }
};
