class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        
        long int reverse = 0;
        long int copy    = x;
        while(x)
        {
            reverse += x%10;
            x >>= 1;
            x /= 5;
            if(x > 0)
                reverse *= 10;
        }
        
        return copy == reverse;
        
    }
};
