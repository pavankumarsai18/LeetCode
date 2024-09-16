class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowSet(9, vector<bool>(10, false));
        vector<vector<bool>> colSet(9, vector<bool>(10, false));
        vector<vector<bool>> subBoardSet(9, vector<bool>(10, false));


        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                int subBoardIdx = (i/3)*3 + (j/3);
                
                if (rowSet[i][num] || colSet[j][num] || subBoardSet[subBoardIdx][num]) {
                    return false;
                }

                rowSet[i][num] = colSet[j][num] = subBoardSet[subBoardIdx][num] = true;
            }
        }

        return true;
    }
};
