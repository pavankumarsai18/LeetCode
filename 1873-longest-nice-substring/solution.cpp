class Solution {
public:
    string getLongestNiceString(string & s, vector<vector<int>> & lowPrefixCount, vector<vector<int>> &upperPrefixCount, int left, int right)
    {
        if(left >= right || left >= s.size() || right >= s.size())
            return "";
        
        int ch;
        for(int cur = left; cur <= right; cur++)
        {
            int count = 0;
            ch = s[cur]-'a';
            if(islower(s[cur]))
            {
                
                count = upperPrefixCount[ch][right+1] - upperPrefixCount[ch][left];
            }
            else
            {
                ch = ch + 'a' - 'A';
                count = lowPrefixCount[ch][right+1] - lowPrefixCount[ch][left];

            }
            
            if(count == 0)
            {
                 string leftPart = getLongestNiceString(s, lowPrefixCount, upperPrefixCount, left, cur-1);
                string rightPart = getLongestNiceString(s, lowPrefixCount, upperPrefixCount, cur+1, right);
                
                if(leftPart.size() >= rightPart.size())
                    return leftPart;
                return rightPart;
            }
            
        }
        
        return s.substr(left, right-left+1);
            
    }
    string longestNiceSubstring(string s) 
    {
        const int n = s.size();
        vector<vector<int>> lowPrefixCount  (26, vector<int>(n+1, 0));
        vector<vector<int>> upperPrefixCount(26, vector<int>(n+1, 0));
        
        
        for(int i = 0; i < n; i++)
        {
            if(islower(s[i]))
            {
                lowPrefixCount[s[i]-'a'][i+1]   = lowPrefixCount[s[i]-'a'][i] + 1;
            }
            else
            {
                upperPrefixCount[s[i]-'A'][i+1] = upperPrefixCount[s[i]-'A'][i] + 1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                lowPrefixCount[j][i+1]   += lowPrefixCount[j][i];
                upperPrefixCount[j][i+1] += upperPrefixCount[j][i];
            }
        }
    
        
        
        return getLongestNiceString(s,lowPrefixCount,upperPrefixCount,0, n-1);
        
        
    }
};
