class Solution {
public:
    bool judgeSquareSum(int c) {
        
        //a^2 + b^2 = c
        // (a/c)* a + (b/c)*b = 1
        // a/c*a = 1 - (b/c)*b
        // sqrt(c) - 1 >= a >= 1
        // sqrt(c) - 1 >= b >= 1
        
        // 16
        // 1 4 9 16
        
        int max = sqrt(c);
        int min = 0;
        for(int i = min; i < max + 1; i++)
        {
            // a = i;
            // b = sqrt(c - i*i)
            int b = sqrt(c - i * i);
            
            if(b*b + i*i == c)
                return true;
        }
        
        return false;
    }
};
