class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLength = 0;


        for (auto num: nums) {
            int length = 0;
            if (seen.find(num - 1) == seen.end()) {
                while (seen.find(num) != seen.end()) {
                    num++;
                    length++;
                }
                if (maxLength < length) maxLength = length;
            }
        }

        return maxLength;
    }
};
