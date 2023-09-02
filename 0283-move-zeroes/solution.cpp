class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int readIdx, writeIdx;
        readIdx = writeIdx = 0;

        for(; readIdx < n; ++readIdx) {
            if (nums[readIdx] == 0) continue;
            nums[writeIdx++] = nums[readIdx];
        }

        for (; writeIdx < n; ++writeIdx) {
            nums[writeIdx] = 0;
        }
    }
};
