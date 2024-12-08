class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = 0;
        while (hi >= lo) {
            int mid = lo + ((hi - lo) >> 1);
            int numbers_skipped = (nums[mid] - nums[0] - mid);
            if (numbers_skipped >= k) {
                hi = mid - 1;
            } else if (numbers_skipped < k) {
                ans = mid;
                lo = mid + 1;
            }
        }
        return nums[0] + k + ans;
    }
};
