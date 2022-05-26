class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        
        const int n = triangle.size();
        vector<int> dp(n, 0);
        
        for(int j = 0; j < n; j++)
        {
            dp[j] = triangle[n-1][j];
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
            
        }
        return dp[0];
        
        
    }
};
