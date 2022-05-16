class Solution {
private:
    int getAdjMines(vector<vector<char>> & board, const vector<vector<int>> & steps, int r, int c)
    {
        const int n = board.size();
        const int m = board[0].size();
        int numMines = 0;
        
        for(auto & step: steps)
        {
            int dr, dc; dr = step[0]; dc = step[1];
            
            if(isValid(r+dr, c+dc, n, m) && board[r+dr][c+dc] == 'M')
            {
                numMines++;
            }
            
        }
        
        return numMines;
    }

    bool isValid(int r, int c, const int n, const int m)
    {
        return (0 <= r && r < n) && (0 <= c && c < m);
    }
    
    
    void bfs( vector<vector<char>>& board, const vector<vector<int>> & steps, int r, int c)
    {

        const int n = board.size();
        const int m = board[0].size();
        
        queue<vector<int>> Q;
        Q.push({r, c});
        
        while(Q.size())
        {
            vector<int> index = Q.front();
            Q.pop();
            int x = index[0];
            int y = index[1];
            
            
            for(auto & step: steps)
            {
                int dx, dy; 
                dx = step[0]; dy = step[1];
                
                if(!isValid(x+dx, y+dy, n, m))
                    continue;
                
                if(board[x+dx][y+dy] != 'E')
                    continue;
                                
                int numAdjMines = getAdjMines(board,steps, x+dx, y+dy);
                
                if(numAdjMines == 0)
                {
                    board[x+dx][y+dy] = 'B';
                    Q.push({x+dx, y+dy});
                }
                else
                {
                    board[x+dx][y+dy] = '0'+numAdjMines;
                }
            }
        }
        
        return;
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        
        int r, c;
        r = click[0]; c = click[1];

        if(board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return board;
        }
        
        const int n = board.size();
        const int m = board[0].size();
        
        const vector<vector<int>> steps = {{-1,0},{0,1},{1,0},{0,-1}, {-1,1}, {1,-1}, {-1,-1}, {1,1}};
        
        int numAdjMines = getAdjMines(board, steps, r,c);         

        if(numAdjMines == 0)
        {
            bfs(board, steps, r, c);
            board[r][c] = 'B';
        }
        else
        {
            board[r][c] = '0'+numAdjMines;
        }

        
        return board;
        
    }
};
