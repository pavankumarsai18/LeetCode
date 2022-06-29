class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 0 || x == 1)
            return x;
        else if(x == 2 || x == 3)
            return 1;
        else if(x == 4 || x == 5 || x == 6 || x == 7 || x == 8)
            return 2;
        
        int lo = 1;
        int hi = x/2;
        
        while(lo < hi)
        {
            long long mid = lo + (hi-lo+1)/2;
            
            if(mid*mid > x)
            {
                hi = mid-1;
            }
            else if(mid*mid <= x)
            {
                lo = mid;
            }
        }
        
        return lo;
        
    }
};
