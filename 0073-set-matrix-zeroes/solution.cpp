class Solution {
public:
    void setRowToZero(vector<vector<int>> & matrix, int rowIdx) {
        const int numCols = matrix[0].size();
        for (int colIdx = 0; colIdx < numCols; colIdx++) {
            matrix[rowIdx][colIdx] = 0;
        }
    }

    void setColToZero(vector<vector<int>> & matrix, int colIdx) {
        const int numRows = matrix.size();
        for (int rowIdx = 0; rowIdx < numRows; rowIdx++) {
            matrix[rowIdx][colIdx] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();

        vector<bool> rowHasZero(numRows, false);
        vector<bool> colHasZero(numCols, false);


        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (matrix[i][j] == 0) {
                    rowHasZero[i] = true;
                    colHasZero[j] = true;
                }
            }
        }


        for (int rowIdx = 0; rowIdx < numRows; ++rowIdx) {
            if (rowHasZero[rowIdx]) {
                setRowToZero(matrix, rowIdx);
            }
        }

        for (int colIdx = 0; colIdx < numCols; ++colIdx) {
            if (colHasZero[colIdx]) {
                setColToZero(matrix, colIdx);
            }
        }

        return;
    }
};
