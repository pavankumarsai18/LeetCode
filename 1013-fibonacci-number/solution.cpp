class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        
        int fib_n_2 = 1;
        int fib_n_1 = 1;
        int temp;
        for(int i = 2; i < n; i++)
        {
            temp     = fib_n_2;
            fib_n_2  = fib_n_1;
            fib_n_1 += temp;
        }
        
        return fib_n_1;
        
    }
};
