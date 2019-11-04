#include <math.h>
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        
        int result = 0;
        
        for(int num = L; num <= R; num++)
        {
            // check if the number ones are pime
            int temp = num;
            int p = 0;
            while(temp > 0)
            {
                int x = (temp & 1) ;
                if(x == 1)
                {
                    p++;
                }
                //cout<< x;
                temp >>= 1;
            }
            //cout<<endl;
            if(p == 2 || p == 3 || p == 5 || p == 7 || p == 11 || p == 13 || p == 17 || p == 19)
                result++;
        }
        
        return result;
        
    }
    
    bool is_prime(int x)
    {
        if(x == 1)
            return false;
        if(x == 2 || x == 3)
            return true;
        if(x %2 == 0)
            return false;
        else
        {
            for(int i = 3; i*i <= x; i++)
            {
                if(x%i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
};
