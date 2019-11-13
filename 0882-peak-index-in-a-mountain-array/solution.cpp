class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {    
        int lo = 0;
        int hi = A.size() - 1;
        int mid = (lo + hi)/2;
        
        while(hi >= lo)
        {
            if(A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            {
                return mid;
            }
            else if(A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
            {
                lo = mid + 1;
            }
            else if (A[mid - 1] > A[mid] && A[mid] > A[mid + 1])
            {
                hi = mid - 1;
            }
            
            mid = (lo + hi)/2;
        }
        
        mid = -1;
        return mid;
        
    }
};
