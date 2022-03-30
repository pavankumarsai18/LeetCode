class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int loRow , hiRow;
        loRow = 0;
        hiRow = matrix.size() - 1;
        
        while(hiRow >= loRow)
        {
            int mid = (loRow + hiRow)/2;
            
            if(target > matrix[mid][0] && target > matrix[mid][matrix[0].size() - 1])
            {
                loRow = mid + 1;
            }
            else if(target < matrix[mid][0])
            {
                hiRow = mid - 1;
            }
            else
            {
                int loCol = 0;
                int hiCol = matrix[mid].size() - 1;
                
                while(hiCol >= loCol)
                {
                    int midCol = (loCol + hiCol)/2;
                    int val = matrix[mid][midCol];
                    if(val > target)
                    {
                        hiCol = midCol - 1;
                    }
                    else if(val < target)
                    {
                        loCol = midCol + 1;
                    }
                    else
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
