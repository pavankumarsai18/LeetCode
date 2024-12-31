class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        int day_idx = 0;
        for (int day = 1; day <= days.back(); ++day) {
            if (day < days[day_idx]) {
                dp[day] = dp[day-1];
            } else {
                day_idx++;
                dp[day] = min({ dp[day-1] + costs[0], 
                                dp[max(0, day-7)] + costs[1],
                                dp[max(0, day-30)] + costs[2]
                            });
            }
        }
        return dp[days.back()];
    }
};
