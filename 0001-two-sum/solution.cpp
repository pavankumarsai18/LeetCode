class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;

        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_index.count(complement)) {
                return {num_index[complement], (int)i};
            }
            num_index[nums[i]] = i;
        }

        return {};
    }
};
