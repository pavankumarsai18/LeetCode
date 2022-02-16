class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int n = nums.size()/2;
        
        for(int i = 0; i < n; i++)
        {

            result = max(result, nums[i]+nums[nums.size() -i-1]);
            
        }
        
        return result;
        
    }
};
