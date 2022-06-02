class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        
        vector<int> result;
        int carry = 0;
        int index = num.size()-1;
        
        while(k > 0 || index >= 0)
        {
            int digit = k%10 + carry;
            
            k >>= 1;
            k /= 5;
            
            if(index < num.size())
                digit += num[index--];
            
            carry = 0;
            
            if(digit >= 10)
            {
                digit -= 10;
                carry = 1;
            }
            
            result.push_back(digit);
            
        }
        
        if(carry)
        {
            result.push_back(carry);
        }
        for(int i = 0; i < result.size()/2; i++)
        {
            swap(result[i], result[result.size()-i-1]);
        }
        return result;
        
    }
};
