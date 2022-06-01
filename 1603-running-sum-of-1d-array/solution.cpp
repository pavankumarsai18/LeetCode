class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> runningSum(nums.size(),nums[0]);
        
        for(int i = 1; i < nums.size();i++)
        {
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        
        return runningSum;
    }
};
