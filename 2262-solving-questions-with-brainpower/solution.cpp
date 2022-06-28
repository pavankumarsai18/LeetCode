class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        const int n = questions.size();
        long long maxPoint[n];
      
            
        for(int i = n-1; i >= 0; i--)
        {
            int point      = questions[i][0];
            int numSkipped = questions[i][1]+1;
            
            long long skippedVal = (i+numSkipped < n)? maxPoint[i+numSkipped]: 0;
            long long nextVal    = (i+1 < n)? maxPoint[i+1]: 0;
            maxPoint[i] = max(nextVal, point + skippedVal);
        }
        
        return maxPoint[0];
        
    }
};
