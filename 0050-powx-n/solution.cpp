class Solution {
public:
    double myPow(double x, int n) 
    {
        if(x == 1 || n == 0)
        {
            return 1;
        }
        long long pow = n;
        double result = 1;
        double pow_x  = x;
        bool   is_neg = false;
        
        if(pow < 0)
        {
            pow *= -1;
            is_neg = true;
        }
        
        
        while(pow)
        {
            if(pow&1)
            {
                result *= pow_x;
            }
            
            pow_x *= pow_x;
            pow >>= 1;
        }
        
        if(is_neg)
        {
            result = 1/result;
        }
        return result;
        
    }
};
