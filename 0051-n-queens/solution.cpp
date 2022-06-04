class Solution 
{
private:
    int n, row, numQueens;
    unordered_set<int> cols, diags, antiDiags;
    vector<vector<string>> result;
    vector<string> board;
public:
    void getEmptyBoard()
    {
        board = vector<string>();
        for(int r = 0; r < n; r++)
        {
            string boardRow = "";
            for(int c = 0; c < n; c++)
            {
                boardRow += ".";
            }
            board.push_back(boardRow);
        }
    }
    
    void addQueen(int r, int c)
    {
        int diag = r + c;
        int antiDiag = r - c;
        
        cols.insert(c);
        diags.insert(diag);
        antiDiags.insert(antiDiag);
        
        board[r][c] = 'Q';
        numQueens++;
    }
    
    void removeQueen(int r, int c)
    {
        int diag = r + c;
        int antiDiag = r - c;
        
        cols.erase(c);
        diags.erase(diag);
        antiDiags.erase(antiDiag);
        
        board[r][c] = '.';
        
        numQueens--;
    }
    
    bool canSafelyAdd(int r, int c)
    {
        int diag = r + c;
        int antiDiag = r - c;
        
        if(diags.find(diag) != diags.end())
            return false;
        if(antiDiags.find(antiDiag) != antiDiags.end())
            return false;
        if(cols.find(c) != cols.end())
            return false;
        
        return true;
    }
    
    void printBoard()
    {
        for(auto & row: board)
        {
            cout<<row<<endl;
        }
        
        cout<<endl; cout<<endl;
    }
    
    void solve()
    {
        for(int c = 0; c < n; c++)
        {
            // cout<<"row "<<row<<" col "<<c<<endl;
            if(canSafelyAdd(row, c))
            {
                // cout<<"can safely add"<<endl;
                addQueen(row, c);            
                
                // printBoard();
                
                if(row == n-1)
                {
                    if(numQueens == n)
                    {
                        vector<string> copy;
                        for(auto & row: board)
                        {
                            copy.push_back(row);
                        }
                        
                        result.push_back(copy);
                    }
                }
                else if(row < n-1)
                {
                    row++;
                    solve();
                    row--;
                }
                
                removeQueen(row, c);
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) 
    {
        if(n == 1)
        {
            return {{"Q"}};
        }
        numQueens = 0;
        this->n = n;
        
        
        for(int i = 0; i < n; i++)
        {
            cols.empty(); diags.empty(); antiDiags.empty();
            
            getEmptyBoard();
            row = 0;
            
            addQueen(0, i);

            row = 1;
            solve();
            
            removeQueen(0, i);

        
        }
        
        return result;
    }
};
