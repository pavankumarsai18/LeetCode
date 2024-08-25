class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MIN;
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int zero_dist = abs(nums[i]);
            if (zero_dist < diff) {
                diff = zero_dist;
                ans = nums[i];
            } else if (zero_dist == diff) {
                ans = max(ans, nums[i]);
            }
        }

        return ans;
    }
};
