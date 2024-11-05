class Solution {
public:

    vector<int> merge(vector<int> & intervalA, vector<int> & intervalB) {
        return {min(intervalA[0], intervalB[0]), max(intervalA[1], intervalB[1])};
    }
    void printDeque(deque<vector<int>>& Stack) {
        for (auto & interval: Stack) {
            cout << "(" << interval[0] << " " << interval[1] << ") ";
        }
        cout << endl;
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> Stack;

        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0]) {
            Stack.push_back(intervals[idx]);
            idx++;
        }

        vector<int> curInterval = std::move(newInterval);
        while (idx < intervals.size()) {
            if (curInterval.empty()) {
                curInterval = intervals[idx];
                idx++;
            }

            while ((!Stack.empty()) && intersects(Stack.back(), curInterval)) {
                curInterval = merge(Stack.back(), curInterval);
                Stack.pop_back();
            }

            Stack.push_back(curInterval);
            curInterval = {};
        }

        if (!curInterval.empty()) {
            Stack.push_back(curInterval);
        }

        return Stack;

    }

    bool intersects(vector<int>& intervalA, vector<int>& intervalB) {
        if (intervalA.empty() || intervalB.empty()) return false;

        int startA = intervalA[0], endA = intervalA[1];
        int startB = intervalB[0], endB = intervalB[1];

        int maxStart = max(startA, startB);
        int minEnd   = min(endA, endB);

        int timeTaken = minEnd - maxStart;

        return timeTaken >= 0;
    }

};

