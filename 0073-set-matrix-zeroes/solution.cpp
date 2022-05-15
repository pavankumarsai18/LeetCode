class Solution {

public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();
        
        bool firstColZero = false;
        
        for(int i = 0; i < numRows; i++)
        {
            if(matrix[i][0] == 0)
                firstColZero = true;
            
            for(int j = 1; j < numCols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < numRows; i++)
        {
            for(int j = 1; j < numCols; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0)
            for(int j = 0; j < numCols; j++)
                matrix[0][j] = 0;
        if(firstColZero)
            for(int i = 0; i < numRows; i++)
                matrix[i][0] = 0;
        
        return;
        
    }
};
