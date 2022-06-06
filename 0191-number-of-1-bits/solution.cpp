class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int numOnes = 0;
        while(n)
        {
            (n&1)?numOnes++:(0);
            n>>=1;
        }
        return numOnes;
    }
};
