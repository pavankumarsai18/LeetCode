class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        int diff = right - left;
        int numBitsCovered = 0;
        
        while(diff)
        {
            numBitsCovered++;
            diff >>= 1;
        }
        
        int result = left & right;
        
        result >>= numBitsCovered;
        result <<= numBitsCovered;
        
        return result;
    }
};
