class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        bool up, down, left, right;
        up = down = left =right = false;
        
        int i_, j_;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == 'R')
                {
                    i_ = i;
                    j_ = j;
                }
            }
        }
        //up
        for(int i = i_ - 1; i >= 0; i--)
        {
            if(board[i][j_] == '.');
            else if(board[i][j_] == 'p')
            {
                up = true;
                break;
            }
            else
            {
                break;
            }
        }
        //down
        for(int i = i_ + 1; i < board.size(); i++)
        {
            if(board[i][j_] == '.');
            else if(board[i][j_] == 'p')
            {
                down = true;
                break;
            }
            else
            {
                break;
            }
        }
        
        //right
        for(int i = j_ + 1; i < board[i_].size(); i++)
        {
            if(board[i_][i] == '.');
            else if(board[i_][i] == 'p')
            {
                right = true;
                break;
            }
            else
            {
                break;
            }
        }
        //
        for(int i = j_ - 1; i >= 0 ; i--)
        {
            if(board[i_][i] == '.');
            else if(board[i_][i] == 'p')
            {
                left = true;
                break;
            }
            else
            {
                break;
            }
        }
        
        int count = 0;
        if(up)
            count++;
        if(down)
            count++;
        if(left)
            count++;
        if(right)
            count++;
        return count;
        
    }
};
