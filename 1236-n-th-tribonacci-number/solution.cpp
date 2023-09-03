class Solution {
public:
    int tribonacci(int n) {

        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        int T_n, T_n1, T_n2;
        T_n = 0, T_n1 = 1, T_n2 = 1;

        for (int i = 3; i <= n; ++i) {
            int temp = T_n2;
            T_n2 += (T_n1 + T_n);
            T_n = T_n1;
            T_n1 = temp;
        }

        return T_n2;
        
    }
};
