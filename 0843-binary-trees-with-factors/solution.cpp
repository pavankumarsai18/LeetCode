class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size();
        
        const int modVal = 1000000007;
        sort(arr.begin(), arr.end());
        

        vector<long long> dp(n, 1);
        unordered_map<int, int> indexMap;
        for(int i = 0; i < n; i++){indexMap[arr[i]] = i;}
        
        
        int num;
        for(int i = 0; i < n; i++)
        {
            num = arr[i];
            for(int j = 0; j < i; j++)
            {
                if(num%arr[j] == 0)
                {
                    int right = num/arr[j];
                    if(indexMap.find(right) != indexMap.end())
                    {
                        dp[i] += dp[j]*dp[indexMap[right]];
                        dp[i] %= modVal;
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            ans += dp[i]; ans %= modVal;
        }
        
        return ans;
        
        
        
    }
};
