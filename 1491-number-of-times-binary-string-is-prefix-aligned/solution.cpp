class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) 
    {
        const int n = flips.size();
        
        int ans = 0;
        int curSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            curSum += (flips[i] - i - 1);
            if(curSum == 0) ans++;
        }
        
        return ans;
        
    }
};
