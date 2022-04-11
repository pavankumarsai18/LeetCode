class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        
        const int numRows = grid.size();
        const int numCols = grid[0].size();
        k = k%(numRows*numCols);
        
        int a = numRows*numCols;
        int b = k;
        const int N = a;
        while(b)
        {
            int temp = b;
            b = a%b;
            a = temp;
        }
        
        int gcd = a;
        
        for(int i = 0; i < gcd; i++)
        {
            int index = i%N;
            int copy = grid[index/numCols][index%numCols];
            
            for(int j = 1; j < N/gcd +1; j++)
            {
                index = (i+j*k)%N;
                std::swap(grid[index/numCols][index%numCols], copy);
            }
        }
       
        
        return grid;
        
    }
};
