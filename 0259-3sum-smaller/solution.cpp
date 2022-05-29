class Solution {
public:
    int twoSumSmaller(vector<int>& nums, int start, int target)
    {
        int num_less_target = 0;
        int left = start;
        int right = nums.size()-1;
        
        while(left < right)
        {
            if(nums[left] + nums[right] < target)
            {
                num_less_target += (right-left);
                left++;
            }
            else
                right--;
        }
        return num_less_target;
    }
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        const int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int num_less_target = 0;
        
        for(int i = 0; i < n; i++)
        {
            num_less_target += twoSumSmaller(nums, i+1, target-nums[i]);
        }
        
        return num_less_target;
        
    }
};
