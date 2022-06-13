class Solution {
public:
    int reverse(int x) 
    {
        if(x == INT_MIN)
            return 0;
        
        int result = 0;
        bool isNeg = (x < 0)? true: false;
        
        if(isNeg)
            x *= -1;
        
        
        while(x)
        {
            int digit = x%10;
            x /= 10;
            
            if(INT_MAX/10 < result)
                return 0;
            
            result *= 10;            
            result += digit;
        }
        return (isNeg)?-1*result:result;
        
    }
};
