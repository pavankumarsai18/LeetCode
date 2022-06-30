class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        const int n = nums.size();

        sort(nums.begin(), nums.end());


        
        int minSteps = 0;
        for(int i = 0; i < n; i++)
        {
           minSteps += abs(nums[n/2] - nums[i]);
        
        }
        
        return minSteps;
        
    }
};
