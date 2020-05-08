class Solution {
private:
    unordered_set<int> Fib;
    vector<int> fib;
public:
    int findMinFibonacciNumbers(int k)
    {

        
        // if k <= 0 then we cannot form the number
        if(k <= 0){
            return -1;
        }
        
        // First we create set and vector which contain the fibonacci numbers
        // if they have not been constructed yet
        if(Fib.size() == 0)
        {
            int a = 1; int b = 1;

            while(a <= k)
            {
                Fib.insert(a);
                fib.push_back(a);
                int temp = b;
                b = a + b;
                a = temp;
            }
        }
        
        
        int ind = fib.size() - 1;
        int n = k;
        int result = 0;
        while(n > 0)
        {
            auto itr = Fib.find(n);
            if(itr != Fib.end())
            {
                result++;
                return result;
            }
            else
            {
                int temp =  findMinFibonacciNumbers(n - fib[ind]);
                
                if(temp != -1)
                {
                    result = temp + 1;
                    return result;
                }
                
                ind--;
            }
            
        }
        
        return result;
    }
};
