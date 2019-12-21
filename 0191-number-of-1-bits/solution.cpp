class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        auto temp = n;
        int result = 0;
        
        while(temp != 0)
        {
            result += temp&1;
            temp >>= 1;
        }
        
        return result;
        
    }
};
