class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n = values.size();
        int maxLeftScore = values[0] - 0;
        int maxScore = 0;
        for (int i = 1; i < n; ++i) {
            maxScore = max(maxScore, values[i] - i + maxLeftScore);
            maxLeftScore = max(maxLeftScore, values[i] + i);
        }

        return maxScore;
    }
};
