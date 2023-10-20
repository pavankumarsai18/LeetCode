class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        const int n = nums.size();

        int curMin = nums[0];
        int curDiff = nums[1] - nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] - curMin > curDiff) {
                curDiff = nums[i] - curMin;
            }

            if (nums[i] < curMin) {
                curMin = nums[i];
            }
        }

        return (curDiff > 0) ? curDiff : -1;
    }
};
