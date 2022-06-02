class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int result = 0;
        
        while(n)
        {
            result ^= (start);
            n--;
            start++; start++;
        }
        
        return result;
    }
};
