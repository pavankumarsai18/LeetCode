class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_val = {{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};
        
        int ans = 0;
        int index = 0;
        while (index < s.size()) {
            if (index + 1 < s.size() 
                    && roman_val[s[index + 1]] > roman_val[s[index]]) {
                
                ans += roman_val[s[index+1]] - roman_val[s[index]];
                index += 2;
            } else {
                ans += roman_val[s[index]];
                index++;
            }        
        }
        
        return ans;
    }
};
