class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1;
        int index = digits.size()-1;
        
        vector<int> result;
        while(index >= 0)
        {
            int newDigit = digits[index] + carry;
            
            if(newDigit >= 10)
            {
                newDigit -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            digits[index] = newDigit;
            index--;
        }
        if(carry)
        {
            digits.push_back(1);
            
            for(int i = 0; i < digits.size()-1; i++)
            {
                digits[i+1] = digits[i];
            }
            digits[0] = 1;
        }
        
        return digits;
        
    }
};
