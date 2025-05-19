class Solution {
public:
    string triangleType(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= nums[(i+1) % n] + nums[(i+2) %n]) {
                return "none";
            }
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
