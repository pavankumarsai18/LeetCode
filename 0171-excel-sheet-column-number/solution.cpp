class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            result += pow(26, s.length() - i - 1)*(static_cast<int>(s[i]) - 64);
        }
        
        return result;
    }
};
