class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        const int n = nums.size();
        
        int diff = INT_MAX;
        int closest_sum = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n && diff != 0; i++)
        {
            int lo = i + 1;
            int hi = n - 1;
            
            while(lo < hi)
            {
                int sum = nums[i]+nums[lo]+nums[hi];
                if(abs(target-sum) < abs(diff))
                {
                    diff = target - sum;
                    closest_sum = sum;
                }
                if(sum < target)
                    ++lo;
                else
                    --hi;
            }
        }
        
        return target - diff;
               
    }
};
