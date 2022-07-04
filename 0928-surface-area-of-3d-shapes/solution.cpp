class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) 
    {
        int area = 0;
        const int n = grid.size();

        int steps[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        int di, dj;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > 0)
                {
                    area += 2 + grid[i][j]*4;
                    for(auto & step: steps)
                    {
                        di = step[0]; dj = step[1];

                        if(i+di < n && i + di >= 0 && j + dj < n && j+dj >= 0)
                            area -= min(grid[i][j], grid[i+di][j+dj]);

                    }
                }
            }
        }
        
        
        return area;
        
    }
};
