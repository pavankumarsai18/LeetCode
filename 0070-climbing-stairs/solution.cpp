class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int cur, prev, temp;
        prev = 1; cur = 2;
        
        for(int steps = 2; steps < n; steps++)
        {
            temp = prev;
            prev = cur;
            
            cur += temp;
        }
        
        return cur;
    }
};
