class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();

        vector<int> ans = prices;
        deque<int> mono_stack;

        for (size_t i = 0; i < n; ++i) {
            while (!mono_stack.empty() &&
                prices[mono_stack.back()] >= prices[i]) {
                ans[mono_stack.back()] -= prices[i];
                mono_stack.pop_back();
            }
            mono_stack.push_back(i);
        }

        return ans;
    }
};
