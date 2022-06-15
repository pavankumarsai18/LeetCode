class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        if(word1 == word2)
            return 0;
        
        
        const int len1 = word1.size();
        const int len2 = word2.size();
        
        if(len1 == 0 || len2 == 0)
            return len1 + len2;
        
        vector<vector<int>>dp(2, vector<int>(len2+1, 0));
        for(int j = 0; j <= len2; j++)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= len1; i++)
        {
            int cur  = i&1;
            int prev = 1^cur;
            dp[cur][0] = i;
            for(int j = 1; j <= len2; j++)
            {
                // If chars are different we need to replace char 
                // which will take 1 additional cost
                int replacechar  = dp[prev][j-1];
                
                if(word1[i-1] == word2[j-1])
                {
                    dp[cur][j] = replacechar;
                }
                else
                {
                    int insertchar   = dp[prev][j];
                    int deletechar   = dp[cur][j-1];
                    
                    insertchar++;
                    deletechar++;
                    replacechar++;
                    
                    dp[cur][j] = min(min(replacechar, insertchar), deletechar);
                }
            }
        }
        
        return dp[len1&1][len2];
        
    }
};
