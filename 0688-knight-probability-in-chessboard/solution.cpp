class Solution {
public:
    double knightProbability(int n, int k, int row, int col) 
    {
        const int numSteps = 8;
        
        const double P     = 0.125;
        
        const int steps[numSteps][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{-2,-1},{2,-1}};
    
        vector<vector<double>> probSquare(n, vector<double>(n, 0.0));
        probSquare[row][col] = 1;
        
        
        for(int move = 1; move <= k; move++)
        {
            vector<vector<double>> newProbSquare(n, vector<double>(n, 0.0));
            for(int x = 0; x < n; x++)
            {
                for(int y = 0; y < n; y++)
                {
                    for(int step = 0; step < numSteps; step++)
                    {
                        int dx, dy; dx = steps[step][0]; dy = steps[step][1];
                        if((0 <= x+dx && x+dx < n) && (0 <= y+dy && y+dy < n))
                        {
                            newProbSquare[x][y] += P*probSquare[x+dx][y+dy];
                        }
                    }
                }
            }
            
            probSquare = newProbSquare;
        }
        
        double ans = 0.0;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                ans += probSquare[row][col];
            }
        }
        
        return ans;
    
    }
};
