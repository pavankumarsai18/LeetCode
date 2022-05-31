class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        if(s.size() < k)
            return false;
        
        const int n                = s.size();
        const int mask             = (1<<(k-1)) - 1;
        const int num_binary_codes = 1<<k;
        
        int discovered_nums = 0;
        
        
        vector<bool> discovered(num_binary_codes, false);

        int num = 0;
        int index = 0;
        while(index < k)
        {
            num |= s[index] - '0';
            
            if(index != k - 1)
                num <<= 1;
            index++;
        }
        discovered_nums++;
        discovered[num] = true;        
        
        while(index < n)
        {       
            num &= mask;            
            num <<= 1;
            num |= s[index]-'0';
            
            if(discovered[num] == false)
            {
                discovered_nums++;
            }
            
            discovered[num] = true;
            index++;
        }
        
        return discovered_nums == num_binary_codes;
        
    }
};
