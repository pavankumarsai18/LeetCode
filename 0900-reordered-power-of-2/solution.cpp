class Solution {
public:
    vector<int> getDigitCount(int n)
    {
        vector<int> digitCount(10, 0);
        
        while(n)
        {
            digitCount[n%10]++;
            n /= 10;
        }
        
        return digitCount;
    }
    
    
    bool reorderedPowerOf2(int n) 
    {
        
        // get the max number possible from n
        // get all the powers of two less than max number
        // for each possible power of two less than or eq to max number
        // check if the number is an anagram of power of two
        
        int power_two  = 1;
        const int max_num_size = 31;
        vector<int> numDigits = getDigitCount(n);
        
        for(int iterations = 0; iterations < max_num_size; iterations++)
        {
            vector<int> powerDigits = getDigitCount(power_two);
            
            bool can_reorder = true;
            
            for(int i = 0; i < 10; i++)
            {
                if(powerDigits[i] != numDigits[i])
                {
                    can_reorder = false;
                    break;
                }
            }
            
            if(can_reorder) return true;
            
            power_two <<= 1;
        }
        
        return false;
        
    }
};
