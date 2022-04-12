class Solution {
public:
    int fixedPoint(vector<int>& arr) 
    {
        
        
        int lo = 0;
        int hi = arr.size() - 1;
        
        int result = -1;
        while(hi >= lo)
        {
            int mid = lo + (hi - lo)/2;
            
            int val = arr[mid] - mid;
            if(val > 0)
            {
                hi = mid - 1;
            }
            else if(val < 0)
            {
                lo = mid + 1;
            }
            else
            {
                result = mid;
                hi = mid - 1;
            }
        }
        return result;
    }
};
