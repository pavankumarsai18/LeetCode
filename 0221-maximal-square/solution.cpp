class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<int>dp(cols+1, 0);
        int maxArea = 0;
        for(int i = 1; i <= rows; i++)
        {
            vector<int> newDP(cols+1, 0);
            for(int j = 1; j <= cols; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    newDP[j] = min(min(dp[j], dp[j-1]), newDP[j-1]) + 1;
                    maxArea  = max(maxArea, newDP[j]);
                }
            }
            dp = newDP;
        }
        
        
        return maxArea*maxArea;
    }
};
