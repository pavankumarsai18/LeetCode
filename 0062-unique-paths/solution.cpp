class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        const int numRows = m;
        const int numCols = n;
        
        
        vector<int> prevRow(n, 1);        
        for(int row = numRows - 2; row >= 0; row--)
        {
            vector<int> newRow(n, 1);
            for(int col = numCols - 2; col >= 0; col--)
            {
                newRow[col]  = newRow[col+1];
                newRow[col] += prevRow[col];
            }
            
            prevRow = newRow;
        }
        
        return prevRow[0];
        
    }
};
