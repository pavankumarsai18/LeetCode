class Solution {
private: 
    const int MOD = 1e9 + 7;
public:
    int modMult (int a, int b) {
        a %= MOD;
        b %= MOD;

        unsigned long long res = a;
        res = (res * b)%MOD;

        return static_cast<int>(res);

    }
    int countOrders(int n) {
        if (n == 1) {
            return 1;
        } if (n == 2) {
            return 6;
        }

        int ans = 6;

        for (int i = 3; i <= n; i++) {
            int N = 2*i - 1;
            int n_2 = (N * (N + 1))/2;
            ans = modMult(ans, n_2);

        }
        return ans;
    }
};
