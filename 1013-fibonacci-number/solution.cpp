class Solution {
public:
    int fib(int n) {
        int a, b;
        a = 0; b = 1;
        if(n == 0)
            return 0;
        else if(n == 1 or n == 2)
            return 1;
        else
        {
            for(int i = 0; i < n; i++){
                int temp = a;
                a = b;
                b = temp + b;
            }
            
            return a;
        }
    }
};
