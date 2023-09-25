class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();

        int numZeros, maxLength, left, right, numOnes, zerosUsed;

        left = right = numZeros  = maxLength = numOnes = zerosUsed = 0;

        for(; right < n; ++right) {
            
            numZeros += (nums[right] == 0);
            numOnes += nums[right];

            if (numZeros > 1) {
                numZeros -= (nums[left++] == 0);
            } 

            int length = right - left + 1 - numZeros;
            if (maxLength < length) {
                zerosUsed = numZeros;
                maxLength = length;
            }
        }

        if (numOnes == 0) return 0;
        if (zerosUsed == 0 && numZeros > 0) {
            return maxLength;
        } else if (numOnes == n) {
            return n - 1;
        }

        return maxLength;
    }
};
