class Solution {
private:
    int number_primes(int n)
    {
        int result = 0;
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        result = 2;
        for(int j = 4; j <= n;j++)
        {
            bool is_prime = true;
            for(int i = 2; i*i <= j; i++)
            {
                if(j%i == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if(is_prime)
                result++;
        }
        return result; 
    }
    int mulmod(int a, int b, const int mod) 
    { 
        int res = 0; // Initialize result 
        a = a % mod; 
        while (b > 0) 
        { 
            // If b is odd, add 'a' to result 
            if (b % 2 == 1) 
                res = (res + a) % mod; 

            // Multiply 'a' with 2 
            a = (a * 2) % mod; 
            // Divide b by 2 
            b /= 2; 
        } 
  
    // Return result 
    return res % mod; 
} 
    vector<int> factorial(int n)
    {
        vector<int> fact;
        const int m = 1000000007;
        fact.push_back(1);
        fact.push_back(1);
        
        for(int i = 2; i < n+1; i++)
        {
            int temp = fact[fact.size() - 1];
            fact.push_back(mulmod(temp, i, m));
        }
        return fact;
        
    }
public:
    int numPrimeArrangements(int n) 
    {
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        vector<int> fact = factorial(n);
        
        const int m = 1000000007;
        
        int x = number_primes(n);
        
        if(x >= n - 1)
            return 0;
        
        return mulmod(fact[n - x], fact[x],m);
    
        
    }
};
