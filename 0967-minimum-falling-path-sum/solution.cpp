class Solution {
private:
    int min(int a, int b)
    {
        return (a<b)?a:b;
    }
    
    int min(int a, int b, int c)
    {
        return min(min(a, b), c);
    }
    
    bool isValid(int x, int y, int size)
    {
        return ( 0 <= x && x < size) && (0 <= y <= size);
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        vector<vector<int>> T;
        for(int i = 0; i < A.size(); i++)
        {
            vector<int> row;
            
            for(int j = 0; j < A[0].size(); j++)
            {
                if(i == 0)
                {
                    row.push_back(A[i][j]);
                }
                else{
                    row.push_back(0);
                }
            }
            
            T.push_back(row);
        }
        
        
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                
                if(j == 0)
                {
                    // cout<<"->"<<i<<" "<<j<<" "<<j+1<<endl;
                     T[i][j] = min(T[i-1][j] + A[i][j], T[i-1][j+1]+A[i][j]);
                }
                else
                {
                    if(j + 1 < A[0].size())
                    {
        
                        T[i][j] = min(A[i][j]+T[i-1][j-1],A[i][j]+T[i-1][j+1], A[i][j]+T[i-1][j]);
                    }
                    else
                    {
                        T[i][j] = min(A[i][j]+T[i-1][j-1], A[i][j]+T[i-1][j]);  
                    }
                }
                
               
                
            }
        }
        
        int result = T[T.size()-1][0];
        for(int j = 0; j < T[0].size(); j++)
        {
           if(result > T[T.size() - 1][j]){
               result = T[T.size()-1][j]; 
           }
        }
        
        return result;
        
    }
};
