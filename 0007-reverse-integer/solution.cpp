class Solution {
public:
    int reverse(int x) 
    {
        if(x == INT_MIN)
            return 0;
        bool isNeg = false;
        if((x>>31)&1){
            isNeg = true;
            x = x*-1;   
        }
        
        
        
        int result = 0;
        
        while(x)
        {
            result += x%10;
            
            // Check overflow
            if(result > INT_MAX/10 && x >= 10)
            {
                return 0;
            }
            if(x >= 10)
            {
                result *= 10;
            }
            x /= 10;
        }
        
        if(isNeg)
            result *= -1;
        return result;
        
        
    }
};
