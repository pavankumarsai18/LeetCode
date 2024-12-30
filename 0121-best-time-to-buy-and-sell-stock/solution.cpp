class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cur_min = prices[0];
        int cur_max = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(profit, cur_max - cur_min);
            cur_max = prices[i];
            if (cur_min > prices[i]) {
                cur_min = prices[i];
            }
        }
        profit = max(profit, cur_max - cur_min);
        return profit;
    }
};
