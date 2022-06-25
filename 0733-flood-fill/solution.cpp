class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        const int n = image.size();
        const int m = image[0].size();
        
        queue<pair<int, int>> Q;
        int steps[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
        
        int curColor = image[sr][sc];
    
        Q.push({sr, sc});
        while(Q.size())
        {
            
            int r, c;
            r = Q.front().first; c = Q.front().second;
            image[r][c] = color;
            Q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int dr; int dc;
                dr = steps[i][0]; dc = steps[i][1];
            
if(r+dr >= 0 && r+dr < n && c+dc >= 0 && c + dc < m && image[r+dr][c+dc] == curColor && image[r+dr][c+dc] != color)
                {
                    Q.push({r+dr, c+dc});            
                }
            }
        }
        
        return image;
        
    }
};
