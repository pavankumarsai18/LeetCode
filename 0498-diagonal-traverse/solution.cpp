class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        
        const int rows = mat.size();
        const int cols = mat[0].size();
        const int total= rows*cols;
        
        int r, c;
        r = c = 0;        
        
        int diagNum = 0;
        vector<int> result;

        int startRow = 0;
        while(startRow < rows)
        {
            vector<int> diag;

            r = startRow;
            c = 0;
            while(r >= 0 && c < cols)
            {
                if(diagNum%2 == 0)
                {
                    result.push_back(mat[r--][c++]);
                }
                else
                {
                    diag.push_back(mat[r--][c++]);
                }
            }
            
            if(diagNum%2 == 1)
            {
                
                for(int i = diag.size()-1; i>=0; i--)
                    result.push_back(diag[i]);
            }
            
            
            startRow++;
            diagNum++;
            
        }

        int startCol = 1;

        while(startCol < cols)
        {
            vector<int> diag;
            c = startCol;
            r = rows - 1;
            while(r >= 0 && c < cols)
            {
                if(diagNum%2 == 0)
                {
                    result.push_back(mat[r--][c++]);
                }
                else
                {
                    diag.push_back(mat[r--][c++]);
                }
            }

            if(diagNum%2 == 1)
            {
                
                for(int i = diag.size()-1; i>=0; i--)
                    result.push_back(diag[i]);
            }
            diagNum++;
            startCol++;
        }

        return result;


        
        
    }
};
