class Solution {
public:
    bool checkPrime(int num)
    {
        if(num == 2 || num == 3)
            return true;
        for(int i = 2; i*i <= num; i++)
        {
            if(num%i == 0)
                return false;
        }
        
        return true;
    }
    int countPrimes(int n) 
    {
        if(n == 0 || n == 1)
            return 0;

        n--;
        const int size = n+1;
        vector<bool>isPrime(size, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int num = 2; num*num <= n; num++)
        {
            if(isPrime[num])
            {
                for(int multiple = num*num; multiple <= n; multiple += num)
                {
                    isPrime[multiple] = false;
                }
            }
        }
        
        int numPrime = 0;
        for(int i = 2; i < n+1; i++)
        {
            numPrime += isPrime[i];
        }
        return numPrime;
        
    }
};
