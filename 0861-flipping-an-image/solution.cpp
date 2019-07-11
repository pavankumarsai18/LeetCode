class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
       
        for(int i = 0; i < row; i++)
        {
              // Reverse each row
            for(int j = 0; j < col/2; j++)
            {
                int temp = A[i][j];
                A[i][j] = A[i][col - j - 1];
                A[i][col - 1 - j] = temp;
                
            }
            
            // make 0 to one and one to 0
            for(int j = 0; j < col; j++)
            {
                A[i][j] = A[i][j] ^ 1; 
            }
             
            
        }
        
        return A;
    }
};
