class Solution {
public:
    void traverseAndSortDiag(array<int, 2> & pos, vector<vector<int>>& mat, const int & numRows, const int& numCols)
    {
        int s_row, s_col;
        s_row = pos[0]; s_col = pos[1];
        
        vector<int> diagonal;
        
        while(s_row < numRows && s_col < numCols)
        {
            diagonal.push_back(mat[s_row][s_col]);
            s_row++; s_col++;
        }
        
        sort(diagonal.begin(), diagonal.end());
        
        s_row = pos[0]; s_col = pos[1];
        
        int cur_index = 0;
        while(s_row < numRows && s_col < numCols)
        {
            mat[s_row][s_col] = diagonal[cur_index];
            s_row++; s_col++;
            cur_index++;
        }
        
        return;
        
    }
    
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        
        const int numRows = mat.size();
        const int numCols = mat[0].size();
        
        vector<array<int, 2>> startPos;
        for(int row = numRows-1; row >= 0; row--)
        {
            startPos.push_back({row, 0});
        }
        
        for(int col = 1; col < numCols; col++)
        {
            startPos.push_back({0, col});
        }
        
        for(auto & start: startPos)
        {
            traverseAndSortDiag(start, mat, numRows, numCols);
        }
        
        
        return mat;
        
    }
};
