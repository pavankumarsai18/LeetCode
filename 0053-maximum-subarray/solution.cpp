class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        for(auto n: nums)
            sum += n;
        
        int maxSum = INT_MIN;
        int tempSum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            tempSum += nums[i];
            if(maxSum < tempSum)
            {
                maxSum = tempSum;
            }
            if(tempSum < 0)
            {
                tempSum = 0;
            }
        }
        
        return maxSum;
        
    }
};
