class Solution {
public:
    int largestVariance(string s) 
    {
        int freq[26][26][2] = {0};
        
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                freq[i][j][1] = -10000;
        
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            int a = s[i] - 'a';
            for(int b = 0; b < 26; b++)
            {
                if(a == b) continue;
                
                // a & b
                freq[a][b][0]++;
                freq[a][b][1]++;
                
                // b & a
                freq[b][a][1] = freq[b][a][0] - 1;
                if(freq[b][a][0] > 0)
                {
                    freq[b][a][0]--;
                }
                
                ans = max(ans, freq[a][b][1]);
                ans = max(ans, freq[b][a][1]);
            }
        }
        
        return ans;
        
    }
};
