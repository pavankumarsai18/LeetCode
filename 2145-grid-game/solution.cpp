class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long> prefixSum1(grid[0].begin(), grid[0].end());
        vector<long long> prefixSum2(grid[1].begin(), grid[1].end());
        for (int i = 1; i < grid[0].size(); ++i) {
            prefixSum1[i] += prefixSum1[i - 1];
            prefixSum2[i] += prefixSum2[i - 1];
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < grid[0].size();++i) {
            long long top = prefixSum1.back() - prefixSum1[i];
            long long bottom = (i - 1 >= 0) ? prefixSum2[i - 1] : 0;
            long long secondRobot = max(top, bottom);
            ans = min(ans, secondRobot);
        }
        return ans;

    }
};
