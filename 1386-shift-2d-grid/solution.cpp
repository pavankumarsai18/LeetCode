class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        vector<vector<int>> Temp = grid;
        
        for(int i = 0; i < k; i++)
        {
            vector<vector<int>> temp;
            for(int l = 0; l < grid.size(); l++)
            {
                vector<int> A(grid[0].size(),0);
                temp.push_back(A);
            }
            
            for(int row = 0; row < grid.size(); row++)
            {
                for(int col = 0; col < grid[0].size(); col++)
                {
                    if(col != grid[0].size() - 1)
                         temp[row][col + 1] = Temp[row][col];
                    else
                    {
                        if(row == grid.size() - 1)
                            temp[0][0] = Temp[row][col];
                        else
                           temp[row+1][0] =  Temp[row][col];
                    }
                }
            }
            
            Temp = temp;
        }
        return Temp;
        
    }
};
