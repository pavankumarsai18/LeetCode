class Solution {
public:
    int findLargestSubset(vector<vector<int>> & counts, int m, int n)
    {
        
        const int N = counts.size();
        // dp[0, 0, i] = 0
        // dp[m,n,i] = max(dp[m - #0, n - #1, i-1] + 1, dp[m, n, i-1]) 
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // cout<<"size "<< dp.size() <<" "<<dp[0].size()<<endl;
        for(int k = 0; k < N; k++)
        {
            int numZeros, numOnes;
            numZeros = counts[k][0];
            numOnes  = counts[k][1];
            for(int zeros = m; zeros >= numZeros; zeros--)
            {
                for(int ones = n; ones >= numOnes; ones--)
                { 
                    dp[zeros][ones] = max(dp[zeros-numZeros][ones-numOnes] + 1, dp[zeros][ones]);
                }
            }
        }
        
        return dp[m][n];
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int count = 0;
        vector<vector<int>> counts;
        
        for(auto & str: strs)
        {
            int numZeros, numOnes;
            numZeros = numOnes = 0;
            
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == '0')
                    numZeros++;
                else
                    numOnes++;
            }
            
            counts.push_back({numZeros, numOnes});
        }
        
        // sort(counts.begin(), counts.end());
        
        return findLargestSubset(counts, m, n);
        
    }
};
