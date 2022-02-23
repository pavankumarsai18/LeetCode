class Solution {

public:
    unordered_map<int, int> memo;
    int climbStairs(int n) 
    {
        auto itr = memo.find(n);
        if(itr != memo.end())
            return memo[n];
        
        if(n <= 2 && n >= 0)
        {
            memo[n] = n;
            return n;
        }
        
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
        
    }
};
