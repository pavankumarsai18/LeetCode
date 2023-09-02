class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefixMult(n + 1, 1);
        vector<int> suffixMult(n + 1, 1);

        for ( int i = 0; i < n; ++i) {
            prefixMult[i + 1] = prefixMult[i] * nums[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            suffixMult[i] = suffixMult[i+1] * nums[i];
        }

        for ( int i = 0; i < n; ++i) {
            nums[i] = prefixMult[i]*suffixMult[i+1];
        }

        return nums;
    }
};
