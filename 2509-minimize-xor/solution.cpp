class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num_bits = 0;
        while(num2) {
            num_bits += (num2 & 1);
            num2 >>= 1;
        }
        bool new_number[32] = {false};
        for (int i = 31; i >= 0; --i) {
            if (((num1 >> i) & 1) && num_bits > 0) {
                new_number[i] = true;
                num_bits--;
            }
        }
        for (int i = 0; i < 32 && num_bits; ++i) {
            if (new_number[i] == false) {
                new_number[i] = true;
                num_bits--;
            }
        }
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            if (new_number[i] == true) {
                ans = ans | (1 << i);
            }
        }

        return ans;



    }
};
