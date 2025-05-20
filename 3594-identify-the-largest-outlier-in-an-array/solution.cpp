class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long sum = 0;
        unordered_map<int, int> num_count;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            num_count[nums[i]]++;
        }

        int largest_outlier = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int possible_outlier = nums[i];
            num_count[possible_outlier]--;

            int rem_sum = sum - possible_outlier;
            int possible_sum_el = rem_sum / 2;

            if ((rem_sum & 1) == 0 && 
                num_count.count(possible_sum_el) != 0 
                && num_count[possible_sum_el] > 0) {
                largest_outlier = max(largest_outlier, possible_outlier);
        
            }

            num_count[possible_outlier]++;
        
        }

        return largest_outlier;

    }
};
