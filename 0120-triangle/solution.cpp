class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        const int n = triangle.size();
        
        vector<int>dp(n, 0);
        
        for(int i = 0; i < n; i++)
           dp[i] = triangle[n-1][i];
        
        for(int row = n-2; row >= 0; row--)
        {
            vector<int>newDP(n,0);
            for(int col = 0; col < row+1; col++)
            {
                newDP[col] = triangle[row][col] + min(dp[col], dp[col+1]);
            }
            dp = newDP;
        }
        
        
        return dp[0];
    }
};
