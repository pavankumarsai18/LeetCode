class Solution {
public:
    int largestVariance(string s) 
    {
        // dp[c1][c2][0] stores the frequency of c1
        // dp[c1][c2][1] stores the (freq(c1) - freq(c2))
        // ans stores the answer
        
        
        int dp[26][26][2] = {0};
        
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                dp[i][j][1] = -10000; // initalize to minimum -10000 since size of string is at max 10,000
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            int c1 = s[i] - 'a';
            for(int c2 = 0; c2 < 26; c2++)
            {
                if(c1 == c2) continue;
                
                
                // increment dp[c1][c2][0] since we have found c1
                // increment dp[c1][c2][1] for same reason as above
                dp[c1][c2][0]++;
                dp[c1][c2][1]++;
                
                
                // update c2 c1
                dp[c2][c1][1] = dp[c2][c1][0] - 1;
                
        
                if(dp[c2][c1][0] > 0)
                    dp[c2][c1][0]--;
                
                
                // get the maximum
                ans = max(ans, dp[c2][c1][1]);
                ans = max(ans, dp[c1][c2][1]);
            }
        }
        
        return ans;
    }
};
