class Solution {
public:
    int minCost(vector<vector<int>>& costs) 
    {
        const int n = costs.size();
        const int k = 3;
        
        int dp[3];
        int newDP[3];
        
        dp[0] = costs[0][0];
        dp[1] = costs[0][1];
        dp[2] = costs[0][2];
        
        for(int i = 1; i < n; i++)
        {
            newDP[0] = newDP[1] = newDP[2] = 0;
            
            for(int j = 0; j < k; j++)
            {
                newDP[j] = min(dp[(j+1)%k], dp[(j+2)%k]) + costs[i][j];
            }
            
            for(int j = 0; j < k; j++)
            {
                dp[j] = newDP[j];
            }
        }
        
        
        return min(min(dp[0], dp[1]), dp[2]);
    }
};
