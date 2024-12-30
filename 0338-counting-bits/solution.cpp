class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> num_bits (n+1, 0);
        bool odd = true;
        for (int number = 1; number <= n; ++number) {
            num_bits[number] = num_bits[number >> 1] + odd;
            odd = !odd;
        }
        return num_bits;
    }
};
