class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long total = 0;
        int left = 0, right = 0;
        int cur_min = nums[0], cur_max = nums[0];
        long long window_length = 0;

        for (; right < nums.size(); right++) {
            cur_min = min(cur_min, nums[right]);
            cur_max = max(cur_max, nums[right]);

            if (cur_max - cur_min > 2) {
                window_length = (right - left);
                total += ((window_length*(window_length + 1))/2);
                cur_min = cur_max = nums[right];
                left = right;

                while (left > 0 
                    && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    cur_min = min(cur_min, nums[left]);
                    cur_max = max(cur_max, nums[left]);
                }

                if (left < right) {
                    window_length = right - left;
                    total -= (window_length*(window_length+1))/2;
                }

            }
        }

        window_length = (right - left);
        total += (window_length*(window_length+1))/2;

        return total;
    }
};
