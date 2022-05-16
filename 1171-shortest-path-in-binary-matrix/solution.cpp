class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        
        const int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        if(n == 1)
            return 1;
        
        auto isValid = [&n](int x, int y)
        {
            return (x >= 0 && x < n) && (y >= 0 && y < n);
        };
        
        
        queue<pair<int, int>> Q;
        
        Q.push({0,0});
        
        const vector<vector<int>> steps = {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{1,-1},{1,1},{-1,-1}};
        
        grid[0][0] = 1;
        while(Q.size())
        {
            
            pair<int, int> index = Q.front();
            Q.pop();
            
            int x = index.first;
            int y = index.second;
            
            int dx, dy;

            for(auto & step: steps)
            {
                dx = step[0]; dy = step[1];
                if(isValid(x+dx, y + dy) && grid[x+dx][y+dy] == 0)
                {
                    if(grid[x+dx][y+dy] == 0)
                    {
                        if(x+dx == n-1 && y+dy == n-1)
                        {
                            return grid[x][y] + 1;
                        }
                        grid[x+dx][y+dy] = grid[x][y] + 1;
                        Q.push({x+dx, y+dy});
                    }
                }
            }   
        }
        
        return -1;
    }
};
