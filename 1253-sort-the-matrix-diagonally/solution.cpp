class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        if(mat.size() == 0)
            return mat;
        
        // cout<<mat.size()<<endl;
        // cout<<mat[0].size()<<endl;
        int d = 0;
        
        while( d < mat.size() + mat[0].size() - 1)
        {
            // cout<<d<<endl;
            int col, row;
            if(d < mat[0].size())
            {
                vector<int> diag;
                col = d;
                row = 0;
                while(row < mat.size() && col < mat[0].size())
                {
                    diag.push_back(mat[row][col]);
                    row++;
                    col++;
                }
                sort(diag.begin(), diag.end());
                
                row = 0;
                col = d;
                int i = 0;
                while(row < mat.size() && col < mat[0].size())
                {
                    mat[row][col] = diag[i];
                    row++;
                    col++;
                    i++;
                }  
            }
            else
            {
                vector<int> diag;
                int temp = d;
                d -= mat[0].size();
                // cout<<"d "<<d<<endl;
                
                row = d;
                col = 0;
                while(row < mat.size() && col < mat[0].size())
                {
                    diag.push_back(mat[row][col]);
                    row++;
                    col++;
                }
                
                sort(diag.begin(), diag.end());
                
                row = d;
                col = 0;
                int i = 0;
                while(row < mat.size() && col < mat[0].size())
                {
                    mat[row][col] = diag[i];
                    row++;
                    col++;
                    i++;
                }  
                
                d = temp;
            }
            
            d++;
        }
        
        return mat;
    }
};
