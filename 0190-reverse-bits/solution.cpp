class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        int temp = n;
        for(int i = 0; i < 32; i++)
        {
            temp >>= (31 - i);
            temp = temp &1;
            temp <<= i;
            result |= temp;
            temp = n;
            
        }
        
        return result;
    }
};
