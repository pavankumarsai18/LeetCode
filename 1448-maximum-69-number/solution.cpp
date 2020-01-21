class Solution {
public:
    int maximum69Number (int num) 
    {
        vector<int> N;
        while(num != 0)
        {
            N.push_back(num%10);
            num /= 10;
        }
        
        int i = N.size() - 1;
        while(i >= 0)
        {
            if(N[i] != 9)
            {
                N[i] = 9;
                break;
            }
            i--;
        }
        
        int result = 0;
        
        for(i = N.size() - 1; i >= 0; i--)
        {
            result += N[i];
            if(i != 0)
                result *= 10;
        }
        return result;
    }
};
