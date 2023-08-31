class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int other_num = target - nums[i];

            if (seen.find(other_num) != seen.end()) {
                return {seen[other_num], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
