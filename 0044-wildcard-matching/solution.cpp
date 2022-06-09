class Solution {
public:
    bool isMatch(string s, string p) 
    {
        const int n = s.size();
        int m = p.size();
        
        string new_p = "";
        bool is_first = true;
        int i = 0;
        while(i < m)
        {
            if(p[i] != '*')
            {
                new_p += p[i];
                i++;
            }
            while(i < m && p[i] == '*')
            {
                if(is_first){
                    new_p += p[i];
                    is_first = false;
                }
                i++;
            }
            is_first = true;
        }
        
        p = new_p;
        m = p.size();
        vector<bool> dp(m+1, false);
        dp[0] = true;
        if(m > 0 && p[0] == '*')
            dp[1] = true;
        
        for(i = 1; i < n+1; i++)
        {
            vector<bool> newDp(m+1, false);
            for(int j = 1; j < m+1; j++)
            {
                if(p[j-1] == '?' || s[i-1] == p[j-1])
                {
                    newDp[j] = dp[j-1];
                }
                else if(p[j-1] == '*')
                {
                    newDp[j] = newDp[j-1] || dp[j];
                }
            }
            dp = newDp;
        }
        
        return dp[m];

    }
};
