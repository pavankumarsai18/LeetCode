class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxBalls = *max_element(nums.begin(), nums.end());
        int lo = 1;
        int hi = maxBalls;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (isPossible(mid, nums, maxOperations)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(int maxBalls, vector<int>& nums, const int & maxOperations) {
        int totalOperations = 0;

        for (auto & num: nums) {
            totalOperations += ceil(num/ (double) maxBalls) - 1;

            if (totalOperations > maxOperations) return false;
        }
  
        return true;
    }
};
