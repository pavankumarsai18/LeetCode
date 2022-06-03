class NumMatrix {
private:
    const int rows;
    const int cols;
    vector<vector<int>> bit;
public:
    int lsb(int n)
    {
        return n&(-n);
    }
    
    void updateBit(int r, int c, int val)
    {
        for(int i = r; i <= rows; i+=lsb(i))
        {
            for(int j = c; j <= cols; j+=lsb(j))
            {
                bit[i][j] += val;
            }
        }
    }
    
    int queryBit(int r, int c)
    {
        int sum = 0;
        for(int i = r; i > 0; i -= lsb(i))
        {
            for(int j = c; j > 0; j -= lsb(j))
            {
                sum += bit[i][j];
            }
        }
        return sum;
    }
    
    NumMatrix(vector<vector<int>>& matrix):rows(matrix.size()), cols(matrix[0].size())
    {
        bit = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                updateBit(i+1, j+1, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) 
    {
        int old = sumRegion(row,col, row, col);
        row++; col++;
        int diff = val - old;
        updateBit(row, col, diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++;col1++;row2++;col2++;
        
        return queryBit(row2, col2) - queryBit(row2, col1-1) - queryBit(row1-1, col2) + queryBit(row1-1, col1-1);
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
