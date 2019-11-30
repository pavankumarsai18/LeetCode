class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int max_sum = 0;
        int max = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {   
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            if(sum > max_sum)
                max_sum = sum;
        }
        if(max_sum == 0)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(max < nums[i])
                    max = nums[i];
            }
            max_sum = max;
        }
        
        return max_sum;
    }
};
