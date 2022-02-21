class Solution {
public:
    int fib(int n) {
        int prev = 0;
        int cur = 1;
        
        for(int i = 0; i < n; i++)
        {
            int temp = prev;
            prev = cur;
            cur = cur + temp;
        }
        
        return prev;
    }
};
