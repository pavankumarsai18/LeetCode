class Solution {
    bool check_subsq(vector<vector<char>>& board, int sq)
    {
        // cout<<"Checking Squares\n";   
        // 1 --> (0 - 2) i (0 - 2) j
        // 2 --> (0 - 2) i (3 - 5) j
        // 3 --> (0 - 2) i (6 - 8) j
        
        // 4 --> (3 - 5) i (0 - 2) j
        // 5 --> (3 - 5) i (3 - 5) j
        // 6 --> (3 - 5) i (6 - 8) j
        
        // 7 --> (6 - 8) i (0 - 2) j
        // 8 --> (6 - 8) i (3 - 5) j
        // 9 --> (6 - 8) i (6 - 8) j
        
        int lo_r  = 0;
        if(sq <= 3)
            lo_r = 0;
        else if(sq <= 6)
            lo_r = 3;
        else
            lo_r = 6;
        
        int hi_r = lo_r + 2;
        
        int lo_c =  0;
        
        if(sq%3 == 0)
            lo_c = 6;
        else if(sq%3 == 1)
            lo_c = 0;
        else
            lo_c = 3;
        
        
        int hi_c = lo_c + 2;
        
        
        vector<bool> found;
        for(int i = 0; i < 9; i++)
        {
            found.push_back(false);
        }
        // cout<<lo_r<<" r:hr "<<hi_r<<endl;
        // cout<<lo_c<<" c:hc "<<hi_c<<endl;
        for(int i = lo_r; i <= hi_r; i++)
        {
            for(int j = lo_c; j <= hi_c; j++)
            {
                // cout<<i<<" "<<j<<endl;
                if(board[i][j] != '.')
                {
                    cout<<static_cast<int>(board[i][j]) - 49<<endl;
                    if(found[ static_cast<int>(board[i][j]) - 49])
                        return false;
                    found[static_cast<int>(board[i][j]) - 49] = true;
                }
            }
        }
        return true;
        
        
    }
    bool check_row(vector<vector<char>>& board)
    {
        // cout<<"Checking rows\n";
        vector<bool> found;
        for(int i = 0; i < 9; i++)
        {
            found.push_back(false);
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                
                if(board[i][j] != '.')
                {
                    // cout<<static_cast<int>(board[i][j]) - 49<<endl;
                    if(found[static_cast<int>(board[i][j]) - 49])
                        return false;
                    found[static_cast<int>(board[i][j]) - 49] = true;
                }
            }
            for(int k = 0; k < 9; k++)
            {
                found[k] = false;
            }
        }
        return true;
        
    }
    bool check_col(vector<vector<char>>& board)
    {
        // cout<<"Checking columns\n";
        vector<bool> found;
        for(int i = 0; i < 9; i++)
        {
            found.push_back(false);
        }
        
        for(int j = 0; j < board[0].size(); j++)
        {
            for(int i = 0; i < board.size(); i++)
            {
                
                if(board[i][j] != '.')
                {
                    // cout<<static_cast<int>(board[i][j]) - 49<<endl;
                    if(found[static_cast<int>(board[i][j]) - 49])
                        return false;
                    found[static_cast<int>(board[i][j]) - 49] = true;
                }
            }
            for(int k = 0; k < 9; k++)
            {
                found[k] = false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        bool col = check_col(board);
        bool row = check_row(board);
        if(col && row)
        {
            for(int i = 0; i < board.size(); i++)
            {
                // cout<<"Checking "<<i+1<<"square\n";
                if(check_subsq(board, i+1) == false)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};
