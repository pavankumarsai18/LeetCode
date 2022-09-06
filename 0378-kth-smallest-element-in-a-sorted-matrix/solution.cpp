class Solution {
public:
    void getCount(vector<vector<int>>& matrix, int & mid, int & count, int & smaller, int & larger)
    {
        count = 0;
        int row, col;
        const int n = matrix.size();
        row = n - 1; col = 0;
        
        
        
        while(row >= 0 && col < n)
        {
            if(matrix[row][col] <= mid)
            {
                smaller = max(smaller, matrix[row][col]);
                count += row + 1;
                col++;
            }
            else
            {
                larger = min(larger, matrix[row][col]);
                row--;
            }
            
        }
        return;
        
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        const int n = matrix.size();
        
        int lo, hi;
        lo = matrix[0][0]; hi = matrix[n-1][n-1];
        int count, smaller, larger;

        while(lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            
            smaller = matrix[0][0]; larger = matrix[n-1][n-1];
            getCount(matrix, mid, count, smaller, larger);
            
            // cout<<"mid "<<mid<<" count "<<count<<endl;
            if(count == k)
            {
                return smaller;
            }
            else if(count < k)
            {
                lo = larger;
            }
            else
            {
                hi = smaller;
            }
            
        }
        
        // cout<<lo<<endl;
        return lo;
    }
};
