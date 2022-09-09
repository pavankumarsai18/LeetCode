class Solution {
public:
    bool isValidPalindrome(string s, int k)
    {
        const int n = s.size();
        vector<int> dp(n, 0);
        
        int prev, temp;
        for(int i = n-2; i >= 0; i--)
        {
            prev = 0;
            for(int j = i + 1; j < n; j++)
            {
                temp = dp[j];
                
                if(s[i] == s[j])
                {
                    dp[j] = prev;
                }
                else
                {
                    dp[j] = min(dp[j], dp[j-1])+1;
                }
                prev = temp;
            }
            
            
        }
        
        return dp[n-1] <= k;
        
    }
};
