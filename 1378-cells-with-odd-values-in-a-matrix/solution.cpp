class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        //Create a matrix of size m * n
        vector<vector<int>> matrix(n);
        for(int i = 0; i < n; i++)
        {
            matrix[i] = vector<int>(m,0);
        }
        
        
        for(int i = 0; i < indices.size(); i++)
        {
            auto index = indices[i];
            //incrementing row by one
            for(int j = 0; j < m; j++)
            {
                matrix[index[0]][j] += 1;
            }
            
            //increment col by one
            for(int j = 0; j < n; j++)
            {
                matrix[j][index[1]] += 1;
            }
        }
        
        //create a counter variable
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j]%2 == 1)
                    count ++;
            }
        }
        
        return count;
    }
};
