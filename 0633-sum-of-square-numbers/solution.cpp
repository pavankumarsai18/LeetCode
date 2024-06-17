class Solution {
public:
        
    bool judgeSquareSum(int c) {
        for (long a = 0; a*a <= c; ++a) {
            int b = c - (int)a*a;

            bool is_square = false;
            int start = 0, end = b, target = b;
            while (start <= end) {
                const long mid = start + ((end - start) >> 1);
                const long mid_sq = mid*mid;

                if (mid_sq == target) {
                    return true;
                } else if (mid_sq < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
