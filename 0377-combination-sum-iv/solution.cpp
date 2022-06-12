class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        const int n = nums.size();        
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int combSum = 0; combSum <= target; combSum++)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(combSum - nums[i] >= 0)
                {
                    dp[combSum] += dp[combSum - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
