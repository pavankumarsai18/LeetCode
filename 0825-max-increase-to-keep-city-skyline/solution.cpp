class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        vector<int> row_max(grid.size(), 0);
        vector<int> col_max(grid[0].size(), 0);
        
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            int row_max_ = grid[i][0];
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(row_max_ < grid[i][j])
                    row_max_ = grid[i][j];
            }
            row_max[i] = row_max_;
        }
        
        
        for(int j = 0; j < grid[0].size(); j++)
        {
            int col_max_ = grid[0][j];
            for(int i = 0; i < grid.size(); i++)
            {
                if(col_max_ < grid[i][j])
                    col_max_ = grid[i][j];
                
                sum += grid[i][j];
            }
            col_max[j] = col_max_;
        }
        
        
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                result += (row_max[i] < col_max[j]) ? row_max[i]:col_max[j];
            }
        }
        
        return result - sum;
        
        
        
        
    }
};
