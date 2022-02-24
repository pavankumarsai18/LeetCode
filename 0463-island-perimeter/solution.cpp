class Solution {
public:
    bool isValid(const int& r, const int & c, const vector<vector<int>>& grid)
    {
        return ((r>= 0 && r < grid.size()) && (c>= 0 && c< grid[0].size()));         
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        
        int result = 0;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    pair<int, int> index; index.first = i, index.second=j;
                    q.push(index);
                    break;
                }
            }
        }
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        if(q.size() == 0)
            return result;
        
        
        while(q.size())
        {
            pair<int, int> index = q.front();q.pop();
            
            if(visited[index.first][index.second] == false)
            {
                int perimeter = 4;
                visited[index.first][index.second] = true;;
                
                int row = index.first;
                int col = index.second;
                
                // right
                if(isValid(row+1, col, grid) && grid[row+1][col] == 1)
                {
                    pair<int, int> index; index.first = row+1, index.second=col;
                    q.push(index);
                    perimeter -= 1;
                }
                // left
                if(isValid(row-1, col, grid) && grid[row-1][col] == 1)
                {
                    pair<int, int> index; index.first = row-1, index.second=col;
                    q.push(index);
                    perimeter -= 1;
                }
                //up
                if(isValid(row, col+1, grid) && grid[row][col+1] == 1)
                {
                    pair<int, int> index; index.first = row, index.second=col+1;
                    q.push(index);
                    perimeter -= 1;
                }
                // down
                if(isValid(row, col-1, grid) && grid[row][col-1] == 1)
                {
                    pair<int, int> index; index.first = row, index.second=col-1;
                    q.push(index);
                    perimeter -= 1;
                }
                result += perimeter;
            }
        }
        return result;
        
        
        
    }
};
