class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int maxDiff = 0;

        for (int i = 1; i < prices.size(); ++i) {
            maxDiff = max(prices[i] - curMin, maxDiff);
            if (curMin > prices[i]) curMin = prices[i];
        }

        if (maxDiff < 0) return 0;
        return maxDiff;

    }
};
