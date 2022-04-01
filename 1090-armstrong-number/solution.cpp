class Solution {
public:
    bool isArmstrong(int n) 
    {
        int result = 0;
        
        int copy = n;
        int numDigits = 0;
        while(copy != 0)
        {
            numDigits++;
            copy >>= 1;
            copy /= 5;   
        }
        
        copy = n;
        while(copy != 0)
        {
            int digit = copy%10;
            
            if(digit != 0)
                result += int(pow(digit, numDigits));
            copy >>= 1;
            copy /= 5;
        }
        
        return result == n;
    }
};
