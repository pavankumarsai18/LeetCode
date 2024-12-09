class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1.0 || n == 0) {
            return 1.0;
        }

        if (n < 0 ) {
            if (n == INT_MIN) {
                return (1.0/myPow(x, INT_MAX)) * (1.0/x);
            }
            return 1.0/myPow(x, -n);
        } 

        double ans = 1.0f;
        double x_power = x;
        while (n) {
            if (n & 1) {
                ans *= x_power;
            }
            x_power *= x_power;
            n >>= 1;
        }

        return ans;
    }
};
