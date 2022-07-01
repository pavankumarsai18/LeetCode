class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        const int n = nums.size();
        int left    = 0;
        int length  = INT_MAX;
        int sum     = 0;
        
        
        for(int right = 0; right < n; right++)
        {
            sum += nums[right];   
            
            while(left <= right && sum >= target)
            {
                sum -= nums[left++];
                if(sum < target && (right-left+2) < length)
                {
                    length = right-left+2;
                }

            }
        }
        
        
        return (length>n)? 0: length;
        
        
    }
};
