class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double champagne [101][101] = {0.0};
        champagne[0][0] = poured;

        for (int row = 0; row <= query_row; ++row) {
            for (int col = 0; col <= row; ++col) {
                double sideOverflow = (champagne[row][col] - 1.0)/2;

                if (sideOverflow > 0) {
                    champagne[row+1][col] += sideOverflow;
                    champagne[row + 1][col + 1] += sideOverflow;
                }
            }
        }

        return min(1.0, champagne[query_row][query_glass]);
    }
};
