class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();
        
        int lo = 0;
        int hi = numRows*numCols - 1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            
            int col = mid%numCols;
            int row = (mid - col)/numCols;
            
            if(matrix[row][col] < target)
            {
                lo = mid + 1;
            }
            else if(matrix[row][col] > target)
            {
                hi = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
        
    }
};
