class Solution {
public:
    int getSum(int a, int b) 
    {
        int sum = 0;
        unsigned int carry = 0;
        
        for (int i = 0; i < 32; i++)
        {
            int A = a & (1 << i);
            int B = b & (1 << i);
            sum |= A ^ B ^ carry;
            carry = ((A & B) | (B & carry) | (A & carry)) << 1;
        }
        
        return sum;
    
    }
};
