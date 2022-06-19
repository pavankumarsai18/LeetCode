class Solution {
public:
    int minimumNumbers(int num, int k) 
    {
        if(num == 0)
            return 0;
        if(num < k)
            return -1;
        if(num == k || num%10 == k)
            return 1;
        
        if(num%2 == 1 && k%2 == 0)
            return -1;
        
        int digit = num%10;
        for(int i = 1; i <= 9; i++)
        {
            int product = k*(i+1);
            if(product%10 == digit && product <= num)
            {
                return (i+1);
            }
        }
        return -1;
        
        
        
    }
};
