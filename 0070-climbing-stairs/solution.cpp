class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int num_ways_cur_step = 2, num_ways_prev_step = 1;
        for (int cur_step = 3; cur_step <= n; cur_step++) {
            int temp = num_ways_cur_step;
            num_ways_cur_step += num_ways_prev_step;
            num_ways_prev_step = temp;
        }

        return num_ways_cur_step;
        
    }
};
