class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        int oneStep = 1;
        int twoStep = 2;
        
        for(int i = 0; i < n - 2; i++)
        {
            int temp = oneStep;
            oneStep = twoStep;
            twoStep = twoStep + temp;
            
        }
        return twoStep;
        
    }
};
