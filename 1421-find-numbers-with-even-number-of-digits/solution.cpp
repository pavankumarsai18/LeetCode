class Solution {
private:
    int findNumDigits(const int& N)
    {
        if(N == 0)
        {
            return 1;
        }
        
        int numDigits = 0;
        int num = N;
        while(num != 0)
        {
            num /= 10;
            numDigits++;
        }
        
        return numDigits;
    }
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(auto & num: nums)
        {
            int numDigits = findNumDigits(num);
            
            if(numDigits%2 == 0){
                // cout<<num<<endl;
                result ++;
            }
        }
        return result;
    }
};
