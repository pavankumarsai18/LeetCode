class Solution {
public:    
    int maxSubArrayLen(vector<int>& nums, int k) {
        int length = nums.size();
        vector<long long> prefix_sum(length + 1, 0);
        int maxLengthSoFar = 0;
        unordered_map<long long, int> sum_seen;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
            if (sum_seen.find(prefix_sum[i+1]) == sum_seen.end()) {
                sum_seen[prefix_sum[i+1]] = i + 1;
            }
            if (prefix_sum[i+1] == k) {
                maxLengthSoFar = max(maxLengthSoFar, (i+1));
            } else {
                long long target_sum = prefix_sum[i+1] - k;
                
                if (sum_seen.find(target_sum) != sum_seen.end()) {
                    maxLengthSoFar = max(maxLengthSoFar, (i + 1 - sum_seen[target_sum]));
                }
            }
        }
        
        
        
        return maxLengthSoFar;
    }
};
