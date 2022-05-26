class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int numOnes = 0;
        while(n)
        {
            if(n&1)
                numOnes++;
            n >>= 1;
        }
        return numOnes;
        
    }
};
