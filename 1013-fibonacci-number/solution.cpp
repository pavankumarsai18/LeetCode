class Solution {
public:
    int fib(int n) 
    {
        int first, second;
        first = 0; second = 1;
        
        for(int i = 0; i < n; i++)
        {
            int next = first + second;
            first  = second;
            second = next;
        }
        
        return first;
        
    }
};
