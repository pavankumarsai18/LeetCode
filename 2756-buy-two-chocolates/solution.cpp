class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int n = prices.size();

        int minimum = min(prices[0], prices[1]);
        int secondMin = max(prices[0], prices[1]);

        for (int i = 2; i < n; ++i) {
            if (prices[i] < minimum) {
                secondMin = minimum;
                minimum = prices[i];
            } else if (prices[i] < secondMin) {
                secondMin = prices[i];
            }
        }

        int total = secondMin + minimum;
        return total > money ? money : money - total;
    }
};
