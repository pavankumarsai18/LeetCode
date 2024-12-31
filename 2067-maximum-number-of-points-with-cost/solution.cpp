class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> row(points[0].begin(), points[0].end());
        int num_rows = points.size(), num_cols = points[0].size();

        vector<long long> left_max(num_cols, 0);
        vector<long long> right_max(num_cols, 0);
        vector<long long> cur_row(num_cols, 0);

        for (int row_idx = 1; row_idx < points.size(); row_idx++) {
            left_max.assign(left_max.size(), 0);
            right_max.assign(right_max.size(), 0);


            left_max[0] = row[0];            
            for (int col_idx = 1; col_idx < num_cols; col_idx++) {
                left_max[col_idx] = 
                    max(left_max[col_idx - 1] - 1, row[col_idx]);
            }

            right_max.back() = row.back();
            for (int col_idx = num_cols - 2; col_idx >= 0; col_idx--) {
                right_max[col_idx] = 
                    max(right_max[col_idx + 1] - 1, row[col_idx]);
            }

            for (int col_idx = 0; col_idx < num_cols; col_idx++) {
                cur_row[col_idx] = points[row_idx][col_idx];
                cur_row[col_idx] += max(left_max[col_idx], right_max[col_idx]);
            }
            row = cur_row;
        }

        return *max_element(row.begin(), row.end());
    }
};
