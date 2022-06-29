class Solution {
public:
    int maxRotateFunction(vector<int>& nums)
    {
        const int n = nums.size();
    
        int sum = nums[0];
        int cur = 0;
        
        for(int i = 1; i < n; i++)
        {
            cur += i*nums[i];
            sum += nums[i];
        }
        
        int ans = cur;
        for(int i = 1; i < n; i++)
        {
            cur += sum - n*nums[n-i];
            if(cur > ans)
                ans = cur;
        }
        
        return ans;
        
        
    }
};
