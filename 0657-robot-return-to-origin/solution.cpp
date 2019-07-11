class Solution {
public:
    bool judgeCircle(string moves) {
        int dir[] = {0, 0, 0, 0};
        
        for(int i = 0; i < moves.length(); i++)
        {
            if(moves[i] == 'U')
            {
                dir[0] += 1;
            }
            
            else if(moves[i] == 'D')
            {
                dir[1] += 1;
            }
            
            else if(moves[i] == 'L')
            {
                dir[2] += 1;
            }
            
            else
            {
                dir[3] += 1;
            }
        }
        
        return (dir[0] == dir[1] && dir[2] == dir[3]);
        
    }
};
