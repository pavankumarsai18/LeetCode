class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;

        if(nums.size() == 0 || nums.size() == 1)
        {
            return 0;
        }
        else
        {
            for(int i = 1; i < nums.size(); i++)
            {
                int prev = nums[i - 1];
                int cur = nums[i];
                
                if(prev < cur)
                {
                    continue;
                }
                else
                {
                    nums[i] = cur + (prev - cur + 1);
                    result += prev - cur + 1;
                }
            }
        }
        
        return result;
        
        
    }
};
