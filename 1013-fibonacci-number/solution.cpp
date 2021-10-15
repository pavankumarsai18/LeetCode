class Solution {
public:
    int fib(int n) {
        int n1, n2;
        
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1 || n == 2)
        {
            return 1;
        }
        else
        {
            
            n1 = 0;
            n2 = 1;
            
            for(int i=1; i <= n; i++)
            {
                int temp = n2;
                n2 = n1 + n2;
                n1 = temp;
            }
            
            return n1;
        }
        
        return n1;
    }
};
