class TicTacToe {
private:
    bool gameOver;
    int n;
    vector<int> diag1, diag2;
    vector<vector<int>> colSum, rowSum;
    int count;
public:
    TicTacToe(int n) {
        gameOver = false;
        this->n = n;
        for(int i = 0; i < n; i++)
        {
            rowSum.push_back(vector<int>(2,0));
        }
        for(int i = 0; i < n; i++)
        {
            colSum.push_back(vector<int>(2,0));
        }
        
        diag1 = {0,0};
        diag2 = {0,0};
        count = 0;
    }
    
    int move(int row, int col, int player) 
    {
        if(!gameOver)
        {
            count++;
            if(row == col)
            {
                diag1[player-1]++;
            }
            if(row == n - 1 - col)
            {
                diag2[player-1]++;
            }
            
            rowSum[row][player-1]++;
            colSum[col][player-1]++;
            
            if(diag1[player-1] == n || diag2[player-1] == n || rowSum[row][player-1] == n || colSum[col][player-1]==n)
            {
                gameOver = true;
                return player;
            }
            
        }
        if(count == n*n)
        {
            gameOver = true;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
