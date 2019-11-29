class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        //O(n)
        
        if(prices.size() <= 2)
        {
            if(prices.size() == 0)
                return 0;
            else if(prices.size() == 1)
                return 0;
            else
                if(prices[0] < prices[1])
                    return prices[1] - prices[0];
        }
        int sum = 0;
        
        
//         int buy = prices[0];
//         int sell = prices[0];
        
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i] < prices[i + 1])
            {
                sum += prices[i + 1] - prices[i];
            }
        }
        
        return sum;
    }
    
};
