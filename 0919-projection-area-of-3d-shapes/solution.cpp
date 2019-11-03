class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) 
    {
        //grid[x][y] == z
        
        //projection in xz plane
        //we compute max z along each x
        int max_xz = 0;
        int sum_xz = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(max_xz < grid[i][j])
                    max_xz = grid[i][j];
            }
            sum_xz += max_xz;
            max_xz = 0;
        }
        
        //projection in yz plane
        // we compute max z along each y
        int max_yz = 0;
        int sum_yz = 0;
        
        int i = 0;
        for(int j = 0; j < grid[i].size(); j++)
        {
            for(i; i < grid.size(); i++)
            {
            
                if(max_yz < grid[i][j])
                    max_yz = grid[i][j];
            }
            sum_yz += max_yz;
            max_yz = 0;
            i = 0;
        }
        
        //projection in xy plane
        //we sum the cubes if there are present on the grid
        int sum_xy = 0;
        for(int i = 0; i < grid.size() ; i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] > 0)
                    sum_xy ++;
            }
        }
        
        
        return sum_xy + sum_yz + sum_xz;
    }
};
