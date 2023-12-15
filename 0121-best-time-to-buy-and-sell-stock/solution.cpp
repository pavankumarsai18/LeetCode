class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int maxDiff = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - curMin;

            maxDiff = max(maxDiff, diff);
            curMin = min(curMin, prices[i]);
        }

        return maxDiff;

    }
};
