class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<string> board;
        for(int i = 0; i < 3; i++)
            board.push_back("---");
    
        for(int i = 0; i < moves.size(); i++)
        {
            
            
            char player = 'O';
            if(i%2 == 0)
            {
                player = 'X';
            }
            
            board[moves[i][0]][moves[i][1]] = player;
            
            // check rows for win
            for(int i = 0; i < 3; i++)
            {
                if(board[i] == "XXX")
                    return "A";
                else if(board[i] == "OOO")
                    return "B";
            }
            
            // check rows for win
            for(int i = 0; i < 3; i++)
            {
                string s = "";
                for(int j = 0; j < 3; j++){
                    s += board[j][i];
                }
                if(s == "XXX")
                    return "A";
                else if(s == "OOO")
                    return "B";
            }
            
            
            // check diagonals for win
            string s = "";
            string a = s + board[0][0];
            string b = s + board[1][1];
            string c = s + board[2][2];
            s = a + b + c;
            if(s == "XXX")
                return "A";
            else if(s == "OOO")
                return "B";

            
            s = "";
            a = s + board[0][2];
            b = s + board[1][1];
            c = s + board[2][0];
            s = a + b + c;
 
            
            if(s == "XXX")
                return "A";
            else if(s == "OOO")
                return "B";
            
        }
        
        if(moves.size() ==  9)
            return "Draw";
        return "Pending";
    }
};
