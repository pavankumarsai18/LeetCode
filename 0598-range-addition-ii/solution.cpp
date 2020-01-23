class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        int min_x = m;
        int min_y = n;
        
        for(int i = 0; i < ops.size(); i++)
        {
            int x = ops[i][0];
            int y = ops[i][1];
            if(x < min_x)
                min_x = x;
            if(y < min_y)
                min_y = y;
        }
        
        return min_x*min_y;
    }
};
