class Solution {
private:
    bool check_diag(vector<vector<int>>& M, int i, int j)
    {
        int I = i;
        int J = j;
        
        int num = M[i][j];
        
        while(J < M[0].size() && I < M.size())
        {
            if(num == M[I][J])
            {
                I += 1;
                J += 1;
            }
            else
                return false;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        // M * N
        // M rows and N columns
        
        // (0,0) (1, 1) (2, 2) ... (M, )
        // (0, 1) (1, 2) (2, 3) .........(min(M, N), M)
        // .
        // .
        // (0, N)
        
        // (1, 0) (2, 1) (3, 2) ......
        // (2, 0) ......
        
        int min = matrix.size();
        if(min > matrix[0].size())
            min = matrix[0].size();
        
        
        int i = 0, j = 0;
        for(int j_ = 0; j_ < matrix[0].size(); j_++)
        {
            if(check_diag(matrix, i, j_) == false)
                return false;
        }
        for(int i_ = 0; i_ < matrix.size(); i_++)
        {
            if(check_diag(matrix, i_, j) == false)
                return false;
        }
        
        return true;
    }
};
