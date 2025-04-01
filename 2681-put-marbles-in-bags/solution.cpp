class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> splits(weights.size() - 1, 0);
        for (size_t i = 0; i < weights.size() - 1; ++i) {
            long long split = static_cast<long long>(weights[i]) +
            static_cast<long long>(weights[i+1]);
            splits[i] += split;
        }

        sort(splits.begin(), splits.end());
        long long ans = 0;
        for (int i = 0;  i < k - 1; ++i) {
            ans += splits[weights.size() - 2 - i] - splits[i];
        }

        return ans;
    }
};
