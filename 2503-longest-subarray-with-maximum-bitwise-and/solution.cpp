class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int currentStreak = 0, maxVal = 0, ans = 0;

        for (int num: nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }

        return ans;


    }
};
