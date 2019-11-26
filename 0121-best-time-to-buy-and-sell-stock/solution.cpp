class Solution {
public:

    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;

        int min = prices[0];
        int max = prices[0];
        int result = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(max < prices[i])
            {
                max = prices[i];
            }
            if(min > prices[i])
            {
                min = prices[i];
                max = prices[i];
            }
            
            if(result < max - min)
            {
                result = max - min;
            }
            
        }
        
        
        return result;
    }
    
};
