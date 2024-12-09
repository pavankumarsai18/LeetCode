class Solution {
public:
    bool is_magic_square(int start_r, int start_c, vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        int end_r = start_r + 2;
        int end_c = start_c + 2;

        if (end_r >= num_rows && end_c >= num_cols) {
            return false;
        }

        array<int, 3> row_sum;
        array<int, 3> col_sum;
        int diag_sum1 = 0, diag_sum2 = 0;

        unordered_set<int> unique_nums;
        for (int r = start_r; r <= end_r; r++) {
            for (int c = start_c; c <= end_c; c++) {
                if ( grid[r][c] > 9 || grid[r][c] <= 0) {
                    return false;
                }
                row_sum[r - start_r] += grid[r][c];
                col_sum[c - start_c] += grid[r][c];

                if (r - start_r == c - start_c) {
                    diag_sum1 += grid[r][c];
                } 
                if ((r - start_r) + (c - start_c) == 2) {

                    diag_sum2 += grid[r][c];
                }

                unique_nums.insert(grid[r][c]);
            }
        }


        bool diag_same = (diag_sum1 == diag_sum2);
        bool col_same = (col_sum[0] == col_sum[1]) && (col_sum[1] == col_sum[2]);
        bool row_same = (row_sum[0] == row_sum[1]) && (row_sum[1] == row_sum[2]);

        bool same_value = (diag_sum1 == col_sum[0]) && (diag_sum1 == row_sum[0]);


        return (unique_nums.size() == 9) && diag_same && col_same && row_same && same_value;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int ans = 0;
        for (int start_c = 0; start_c < num_cols - 2; start_c++) {
            for (int start_r = 0; start_r < num_rows - 2; start_r++) {
                if (is_magic_square(start_r, start_c, grid)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
