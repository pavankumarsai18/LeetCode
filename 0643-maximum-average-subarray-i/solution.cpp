class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum, maxSum;
        int left, right;
        left = right = sum = maxSum =  0;
        for (;right < k; ++right) {
            sum += nums[right];
        }

        maxSum = sum;

        for (; right < nums.size(); ++right,++left) {
            sum += nums[right] - nums[left];
            maxSum = max(maxSum, sum);
        }

        return maxSum/(k*1.0);
    }
};
