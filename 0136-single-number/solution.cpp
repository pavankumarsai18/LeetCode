class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rollingXor = 0;

        for (int i = 0; i < nums.size(); ++i) {
            rollingXor ^= nums[i];
        }

        return rollingXor;
    }
};
