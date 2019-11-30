class Solution {
public:
    int arrangeCoins(int n) 
    {
        long double result = n;
        
        //k*k+1 = 2*result
        //k^2 + k - 2*result = 0
        // -1 + sqrt(1 + 8*result)
        // ------------------------
        //          2
        // -1 + sqrt(41)
        //  ------------- =  
        //       2
        
        result = (-1 + sqrt(1 + 8 * result))/2;
        
        return static_cast<int>(result);
    }
};
