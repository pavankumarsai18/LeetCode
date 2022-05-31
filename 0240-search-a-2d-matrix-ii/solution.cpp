class Solution {
public:
    bool search(vector<vector<int>>& M, int startRow, int endRow, int startCol, int endCol, int target)
    {
        if(startRow > endRow || startCol > endCol)
            return false;
        
        int midR = (endRow - startRow)/2 + startRow;
        int midC = (endCol - startCol)/2 + startCol;
        
        if(M[midR][midC] == target)
        {
            return true;
        }
        
        if(M[midR][midC] > target)
        {
    return (search(M, midR, endRow, startCol, midC-1, target) ||search(M, startRow, midR-1, midC, endCol, target) || search(M, startRow, midR-1, startCol, midC-1, target));

        }
    return (search(M, startRow, midR, midC+1, endCol, target) || search(M, midR+1, endRow, startCol, endCol, target));
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();
       
        
        return search(matrix, 0, numRows-1,0, numCols-1, target);
        
    }
};
