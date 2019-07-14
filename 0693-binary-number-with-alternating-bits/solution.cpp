class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        int cur = 0;
        while(n != 0)
        {
            if(prev == -1)
            {
                cur = n&1;
                n >>= 1;
            }
            
            else
            {
                cur = n&1;
                n >>= 1;
                if(cur == prev)
                    return false;
            }
            prev = cur;
            
        }
        return true;
        
    }
};
