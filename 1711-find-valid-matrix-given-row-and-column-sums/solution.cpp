class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix (rowSum.size(), vector<int>(colSum.size(), 0));
        int i = 0, j = 0;
        while (i < rowSum.size() && j < colSum.size()) {
            int val = min(rowSum[i], colSum[j]);
            matrix[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            } else {
                j++;
            }
        }
        return matrix;
        
    }
    
};
