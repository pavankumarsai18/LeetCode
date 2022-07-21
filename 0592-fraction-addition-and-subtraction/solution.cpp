class Solution {
public:
    bool isPrime(int num)
    {
        if(num == 2 || num == 3 || num == 5 || num == 7) return true;
        if(num&1 == 0) return false;
        
        for(int i = 2; i*i <= num; i++, i++)
        {
            if(num%i == 0) return false;
        }
        return true;
    }
    
    void getNextPrime(int & curPrime)
    {
        curPrime++;
        while(!isPrime(curPrime)) { curPrime++; }
        
        return;
    }
    
    void setLCM(int denominator, vector<int> & primes, vector<int> & lcmPowers)
    {
        for(int i = 0; i < primes.size(); i++)
        {
            int prime = primes[i];
            int power = 0;
            
            while(denominator%prime == 0)
            {
                denominator /= prime;
                power++;
            }
            
            lcmPowers[i] = max(lcmPowers[i], power);
        }
        
        int prime = primes.size() == 0? 1: primes[primes.size() -1 ];
        while(denominator != 1)
        {
            getNextPrime(prime);
            primes.push_back(prime);
            int power = 0;
            while(denominator%prime == 0)
            {
                denominator /= prime;
                power++;
            }
            lcmPowers.push_back(power);
        }
        return;
    }
    
    long long gcd(long long a, long long b)
    {
        if(b == 0) return a;
        if(a < b) return gcd(b, a);
        
        long long copy;
        while(b != 0)
        {
            copy = a;
            a = b;
            b = copy%b;
        }
        
        return a;
    }
    
    void reduceFraction(long long & a, long long & b)
    {
     
        bool a_neg = (a < 0)? true: false;
        
        if(a_neg) a *= -1;
        
        long long gcdNum = gcd(a, b);
        
        if(a_neg) a *= -1;
        
        a /= gcdNum; b /= gcdNum;
        return;
    }
    
    
    string simplify(vector<int>& numerators,vector<int>& denominators)
    {
        unordered_set<int> uniqueDenominators(denominators.begin(), denominators.end());
        
        long long ansNumerator   = 0;
        long long ansDenominator = 1;
        
        vector<int> primes;
        vector<int> lcmPowers;
        
        for(int i = 0; i < denominators.size(); i++)
        {
            setLCM(denominators[i], primes, lcmPowers);
        }
        
        long long lcm = 1;
        for(int i = 0; i < primes.size(); i++)
        {
            lcm *= pow(primes[i], lcmPowers[i]);
        }
        
        
        ansDenominator = lcm;
        long long multiplier;
        for(int i = 0; i < denominators.size(); i++)
        {
            multiplier = lcm/denominators[i];
            ansNumerator += static_cast<long long>(numerators[i])*multiplier;
        }

        reduceFraction(ansNumerator, ansDenominator);
                
        int numerator   = static_cast<int>(ansNumerator);
        int denominator = static_cast<int>(ansDenominator);
        
        string result = to_string(numerator) + "/" + to_string(denominator);
        
        return result;
        
        
        
    }
    
    string fractionAddition(string expression) 
    {
        
        const int n = expression.size();
        
        vector<int> numerators;
        vector<int> denominators;
        
        
        
        for(int i = 0; i < n; i++)
        {
            string numerator   = "";
            string denominator = "";
            bool isneg = false;
            while(i < n && expression[i] != '/')
            {
                if(expression[i] == '+' || expression[i] == '-')
                {
                    if(expression[i] == '-')
                        isneg = true;
                    i++;
                }
                else
                {
                    numerator += expression[i];
                    i++;
                }
            }
            
            i++; // to skip /
            
            while(i < n && (expression[i] != '+' && expression[i] != '-'))
            {
                denominator += expression[i];
                i++;
            }
            if(i != n-1)
                i--;
            
            
            numerators.push_back(isneg?-1*stoi(numerator):stoi(numerator));
            denominators.push_back(stoi(denominator));
        }
        
        
        return simplify(numerators, denominators);
        
    }
};
