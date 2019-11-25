class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int dx = 0;
        int dy = 0;
        int diag = 0;
        int result = 0;
        
        for(int i = 0; i < points.size() - 1; i++)
        {
            dx = abs(points[i][0] - points[i + 1][0]);
            dy = abs(points[i][1] - points[i + 1][1]);
            diag = 0;
            if(dx > 0 &&  dy > 0)
            {
                if(dx > dy)
                {
                    diag = dy;
                    dx -= diag;
                    dy = 0;
                }
                else
                {
                    diag = dx;
                    dy -= diag;
                    dx = 0;
                }
            }
            
            result += (dx + dy + diag);
        }
        
        return result;
    }
};
