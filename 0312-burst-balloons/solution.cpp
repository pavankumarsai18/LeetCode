class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        vector<int> matrices = {1};
        for(int i = 0; i < nums.size(); i++)
        {
            matrices.push_back(nums[i]);
        }
        matrices.push_back(1);
        
        const int n = matrices.size();

        vector<vector<int>> dp;
        for(int i = 0; i < n; i++)
        {
            dp.push_back(vector<int>(n-i, 0));
        }
        
        // for(auto & item: matrices)
        //         cout<<item<<" ";
        // cout<<endl;
    
        
        for(int length = 3; length <= n; length++)
        {
            for(int i = 0; i < n - length + 1; i++)
            {
                int j = i + length - 1;
                
                dp[i][j-i] = INT_MIN;
                
                for(int k = i+1; k < j; k++)
                {
                    int cost = matrices[i]*matrices[k]*matrices[j];
                    dp[i][j-i] = max(dp[i][j-i], dp[i][k-i] + dp[k][j-k] + cost);
                }
            }
        }
        
        // for(auto & row: dp)
        // {
        //     for(auto & item: row)
        //         cout<<item<<" ";
        //     cout<<endl;
        // }
        return dp[0][n-1];
        
        
        
    }
};
