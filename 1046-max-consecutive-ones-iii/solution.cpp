class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int left, right, numZeros;
        left = right = numZeros = 0;

        int maxLength = 0;

        for(; right < n; ++right) {

            numZeros += (nums[right] == 0);


            if (numZeros > k) {
                numZeros -= (nums[left++] == 0);
            }

            maxLength = max(maxLength, right - left + 1);

        }

        return maxLength;
    }
};
