class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int xorVal = start ^ goal;
        
        int bitFlips = 0;
        
        while(xorVal)
        {
            if(xorVal&1)
            {
                bitFlips++;
            }
            xorVal >>= 1;
        }
        
        return bitFlips;
    }
};
