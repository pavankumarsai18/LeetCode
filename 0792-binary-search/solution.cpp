class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int size = nums.size();
        int lo = 0, hi = size - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};
