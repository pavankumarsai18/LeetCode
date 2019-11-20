class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                
                if(grid[i][j] == 1)
                {
                    bool up,left,right,down;
                    up = down = left  = right = true;
                    int temp = 4;
                    if(j == 0 || j == grid[i].size() - 1)
                    {
                        if(j == 0)
                        {
                            left = false;
                        }
                        if(j == grid[i].size() - 1)
                        {
                            right = false;
                        }
                    }
                    
                    if(i == 0 || i == grid.size() - 1)
                    {
                        if(i == 0)
                            up = false;
                        if(i == grid.size() - 1)
                            down = false;
                    }
                    
                    if(up)
                    {
                        if(grid[i - 1][j] == 1)
                            temp--;
                    }
                    if(down)
                    {
                        if(grid[i+1][j] == 1)
                            temp--;
                    }
                    if(left)
                    {
                        if(grid[i][j - 1] == 1)
                            temp --;
                    }
                    if(right)
                    {
                        if(grid[i][j+1] == 1)
                            temp--;
                    }
                    result += temp;
                }
                
               
            }
        }
        return result;
    }
};
