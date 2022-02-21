class Solution {
public:
    int tribonacci(int n) 
    {
    
        long long trib[3] = {0,1, 1};
     
        for(int i = 0; i < n; i++)
        {
            long long firstTerm = trib[0];
            long long secondTerm = trib[1];
            trib[0] = trib[1];
            trib[1] = trib[2];
            trib[2] = trib[2] + firstTerm + secondTerm;
        }
        
        return static_cast<int>(trib[0]);
        
    }
};
