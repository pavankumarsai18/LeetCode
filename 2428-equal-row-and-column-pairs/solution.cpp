class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        unordered_map<string, int> rowCount;
        unordered_map<string, int> colCount;

        for (int r = 0; r < n; ++r) {
            string number = "";
            for (int c = 0; c < n; ++c) {
                number += to_string(grid[r][c]) + ",";
            }
            rowCount[number]++;
        }

        for(int c = 0; c < n; ++c) {
            string number = "";
            for (int r = 0; r < n; ++r) {
                number += to_string(grid[r][c]) + ",";
            }
            colCount[number]++;
        }

        int ans = 0;
        for (auto & [number, count] : rowCount) {
            if (colCount.find(number) != colCount.end()) {
                ans += count*colCount[number];
            }
        }

        return ans;
    }
};
