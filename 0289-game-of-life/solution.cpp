class Solution {
public:
    bool isValid(const int & r, const int & c, const int & numRows, const int & numCols)
    {
        return (r >= 0 && r < numRows) && (c >= 0 && c < numCols);
    }
    
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        
        // Any live cell with fewer than two live neighbors dies as if caused by under-population.
        // Any live cell with two or three live neighbors lives on to the next generation.
        // Any live cell with more than three live neighbors dies, as if by over-population.
        // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
        
        const int numRows = board.size();
        const int numCols = board[0].size();
    
        // Prev value | New Value | rep Val
        //  0         | 0         | 0
        //  1         | 1         | 1
        //  0         | 1         | 2
        //  1         | 0         | 3
        
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                
                int numLive = 0;
                for(int dx = -1; dx <= 1; dx++)
                {
                    for(int dy = -1; dy <= 1; dy++)
                    {
                        if(dx == 0 && dy == 0) continue;
                        if(isValid(i+dx, j+dy, numRows, numCols))
                        {
                            if(board[i+dx][j+dy] == 1 || board[i+dx][j+dy] == 3)
                                numLive++;
                        }
                    }
                }
                
               if(board[i][j] == 0)
               {
                   if(numLive == 3)
                        board[i][j] = 2;
                }
                else if(board[i][j] == 1)
                {
                    if(numLive < 2 || numLive > 3)
                        board[i][j] = 3;
                }

            }
        }
        
        for(int i =0;i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
        return;
        
        
    }
};
