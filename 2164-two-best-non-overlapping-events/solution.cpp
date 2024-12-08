class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;

        for (auto & event: events) {
            times.push_back({event[0], 1, event[2]});
            times.push_back({event[1] + 1, -1, event[2]});
        } 

        sort(begin(times), end(times));

        int maxSeenSoFar = 0, ans = 0;

        for (auto & time: times) {
            // Start time
            if (time[1] == 1) {
                ans = max(ans, maxSeenSoFar + time[2]);
            } else if (time[1] == -1) { // end time
                maxSeenSoFar = max(maxSeenSoFar, time[2]);
            }
        }

        return ans;
    }
};
