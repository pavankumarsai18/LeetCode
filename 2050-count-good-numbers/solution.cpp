class Solution {
public:
    int pow_(int base, long long power) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        long long mult = base;
        while (power) {
            if (power & 1) {
                ans = (long long) ans * mult % MOD;
            }

            mult = (long long) mult * mult % MOD;
            power >>= 1;
        }

        return (ans % MOD);
    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        const int MOD = 1e9 + 7;

        const int numEven   = 5;  
        const int numPrimes = 4;

        return (long long) pow_(5,  (n + 1)/2) % MOD * pow_(4, n/ 2) % MOD;
    }
};


