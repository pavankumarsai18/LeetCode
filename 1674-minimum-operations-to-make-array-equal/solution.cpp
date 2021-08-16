class Solution {
public:
    int minOperations(int n) 
    {        
        int avg = 0;
        
        for(int i = 0; i < n; i++)
        {
            avg += (2*i + 1);
        }
        avg /= n;
        
        
        int stop = (n%2 == 0)? n/2: (n-1)/2;
        int result = 0;
        
        for(int i = 0; i < stop; i++)
        {
            result += (avg - (2*i + 1));   
        }
        
        
        return result;
    }
};
