class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int cur_fib = 1, prev_fib = 0;
        for (int iter = 2; iter <= n; ++iter) {
            int temp = cur_fib;
            cur_fib += prev_fib;
            prev_fib = temp;
        }
        return cur_fib;
    }
};
