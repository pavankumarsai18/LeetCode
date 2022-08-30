class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // Rotation = Transpose + reflection
        
        
        // x := 0 -> (n+1)/2 y:= 0 -> n/2
        // matrix[x][y] := matrix[y][n-1-x] // transpose + reflection
        
        // matrix[x][y] := matrix[y][x]     //  across diagonal is transpose
        // matrix[y][x] := matrix[y][n-1-x] // reflection
        
        
        
        const int n = matrix.size();
        
        for(int i = 0; i < (n+1)/2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                int temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        
    }
};
