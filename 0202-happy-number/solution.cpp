class Solution {
private:
    int squareDigits(int n)
    {
        int result = 0;
        
        while(n > 0)
        {
            result += (n%10)*(n%10);
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        
        unordered_set<int> numbers;
        
        int squareSum = -1;
        
        while(squareSum != 1)
        {
            if(numbers.find(n) != numbers.end())
            {
                return false;
            }
            if(n == 1)
            {
                return true;
            }
            numbers.insert(n);
            n = squareDigits(n);
            
        }
        
        return false;
    }
};
