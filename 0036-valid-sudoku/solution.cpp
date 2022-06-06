class Solution {
public:
    bool atmostOne(vector<int>& arr)
    {

        for(auto & item: arr)
        {
            if(item  < 1)
                return false;
        }

        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        
        vector<int> subBoards(9, 0);
        vector<int> cols(9, 0);
        vector<int> rows(9,0);
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                int subBoardNumber = (j/3) + (i/3)*3;
                
                if(board[i][j] == '.')
                    continue;
                
                int val = 1 << (board[i][j] - '1');
                
                if((rows[i] & val) > 0)
                {
                    return false;
                }
                rows[i] |= val;
                
                if((cols[j] & val) > 0)
                    return false;
                cols[j] |= val;
                
                if((subBoards[subBoardNumber] & val) > 0)
                    return false;
                subBoards[subBoardNumber] |= val;
            }
        }
        
        return true;
        
        
        
    }
};
