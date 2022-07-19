class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows == 0)
            return {{}};
        if(numRows == 1)
            return {{1}};
        else if(numRows == 2)
            return {{1}, {1, 1}};
        
        vector<vector<int>> ans = {{1},{1,1}};        
        for(int row = 2; row < numRows; row++)
        {
            int lastRow     = row - 1;
            int prevRowSize = ans[lastRow].size();
            vector<int> newRow(prevRowSize + 1, 1);
            
            for(int col = 1; col < prevRowSize; col++)
            {
                newRow[col] = ans[lastRow][col -1] + ans[lastRow][col];
            }
            
            ans.push_back(newRow);
        }
        
        return ans;
        
    }
};
