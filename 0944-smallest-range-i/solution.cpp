class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) 
    {
        int min  = A[0];
        int max = min;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(min > A[i])
                min = A[i];
            if(max < A[i])
                max = A[i];
        }
        
        
        if(max - min > 2 * K)
            return (max-min) - 2*K;
        else
            return 0;
    }
};
