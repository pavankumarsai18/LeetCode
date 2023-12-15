class Solution {
public:
    int helper(vector<int>& coins, int amount, unordered_map<int, int> & memo) {
        if (amount == 0) return 0;
        else if (amount < 0) return -1;
        
        if (memo.find(amount) != memo.end()) return memo[amount];
        
        int ans = INT_MAX;
        for (auto coin : coins) {
            int numCoinsRequired = helper(coins, amount - coin, memo);
            if (numCoinsRequired == -1) {
                continue;
            }
            ans = min(ans,  numCoinsRequired + 1);
        }        

        if (ans == INT_MAX) ans = -1;
        memo[amount] = ans;
        return ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return helper(coins, amount, memo);
    }
};
