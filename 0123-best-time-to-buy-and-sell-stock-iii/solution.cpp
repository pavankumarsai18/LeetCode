class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n = prices.size();
        if(n <= 1)
            return 0;
        
    
        vector<int> left(n, 0);
        vector<int> right(n+1, 0);
        
        int leftMin  = prices[0];
        int rightMax = prices[n-1];
        
        for(int i = 1; i < n; i++)
        {
            left[i] = max(left[i-1], prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
            
            int j = n - i - 1;
            right[j] = max(right[j+1], rightMax-prices[j]);
            rightMax = max(rightMax, prices[j]);
        }
        
        int maxProfit = 0;
        for(int i = 0; i < n; ++i)
        {
            maxProfit = max(maxProfit, left[i] + right[i+1]);
        }
        
        return maxProfit;
        
    }
};
